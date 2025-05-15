#ifdef __WXMSW__
#include <wx/msw/msvcrt.h>      // redefines the new() operator 
#endif
#include <wx/wx.h>
#include <wx/log.h>
#include <wx/event.h>
#include <wx/sound.h>
#include <wx/config.h>
#include "TimerTrayMainFrame.h"
#include "MyTaskbarIcon.h"
#include "Images/hourglass.xpm"
#include "Images/hourglass_inverted.xpm"

TimerTrayMainFrame::TimerTrayMainFrame( wxWindow* parent ) : MainFrame( parent )
{
	SetIcon(wxIcon(hourglass));

	m_pTimer = new wxTimer();
	m_pTimer->SetOwner( this );
	this->Connect( wxEVT_TIMER, wxTimerEventHandler( TimerTrayMainFrame::OnTimer ) );

	FillComboBoxValues();

	LoadLastTimerSetting();

	ReloadTimer();

	CreateTaskBarIcon();
}

TimerTrayMainFrame::~TimerTrayMainFrame()
{
	if (m_pTimer->IsRunning())
	{
		m_pTimer->Stop();
	}

	this->Disconnect(wxEVT_TIMER, wxTimerEventHandler(TimerTrayMainFrame::OnTimer));
	delete m_pTimer;

	delete m_pTaskBarIcon;
	m_pTaskBarIcon = nullptr;

	SaveLastTimerSetting();
}


void TimerTrayMainFrame::OnClose( wxCloseEvent& event )
{
	if (event.CanVeto() == false)
	{
		event.Skip();

		return;
	}

	Hide();
}

void TimerTrayMainFrame::CreateTaskBarIcon()
{
	m_pTaskBarIcon = new MyTaskBarIcon(this);
	
    if ( m_pTaskBarIcon->SetIcon(wxIcon(hourglass),"00:00:00" ) == false )
    {
        wxLogError( "Could not set icon." );
    }

#if defined(__WXOSX__) && wxOSX_USE_COCOA
    m_dockIcon = new MyTaskBarIcon( wxTBI_DOCK );
    if ( !m_dockIcon->SetIcon( wxICON( icon ) ) )
    {
        wxLogError( "Could not set icon." );
    }
#endif
}

void TimerTrayMainFrame::LoadLastTimerSetting() const
{
	wxConfig* config = new wxConfig( "TimerTray" );

	long index = config->ReadLong("Hours", 0);
	if (index > 0 && index < static_cast<long>(m_hoursCb->GetCount()) - 1)
	{
		m_hoursCb->SetSelection(config->ReadLong("Hours", 0));
	}
	else
	{
		m_hoursCb->SetSelection(0);
	}

	index = config->ReadLong("Minutes", 0);
	if (index > 0 && index < static_cast<long>(m_minutesCb->GetCount()) - 1)
	{
		m_minutesCb->SetSelection(index);
	}
	else
	{
		m_minutesCb->SetSelection(0);
	}

	index = config->ReadLong("Seconds", 0);
	if (index > 0 && index < static_cast<long>(m_secondsCb->GetCount()) - 1)
	{
		m_secondsCb->SetSelection(index);
	}
	else
	{
		m_secondsCb->SetSelection(0);
	}

	delete config;
}

void TimerTrayMainFrame::SaveLastTimerSetting() const
{
	wxConfig* config = new wxConfig( "TimerTray" );

	config->Write( "Hours", m_hoursCb->GetCurrentSelection() );
	config->Write( "Minutes", m_minutesCb->GetCurrentSelection() );
	config->Write( "Seconds", m_secondsCb->GetCurrentSelection() );

	delete config;
}

void TimerTrayMainFrame::FillComboBoxValues() const
{
	for ( int i = 0; i < 12; i++ )
	{
		m_hoursCb->Insert( wxString::Format( wxT( "%i" ), i ), i );
	}
	m_hoursCb->SetSelection( m_hours );

	for ( int i = 0; i < 60; i++ )
	{
		m_minutesCb->Insert( wxString::Format( wxT( "%i" ), i ), i );
	}
	m_minutesCb->SetSelection( m_minutes );

	for ( int i = 0; i < 60; i++ )
	{
		m_secondsCb->Insert( wxString::Format( wxT( "%i" ), i ), i );
	}
	m_secondsCb->SetSelection( m_seconds );
}

void TimerTrayMainFrame::StartTimer()
{
	m_pTimer->Start( 1000 );
	m_startResetBtn->SetLabelText( "Reset" );
	m_iconizeOnTimerTick = true;
}

void TimerTrayMainFrame::StopTimer()
{
	m_pTimer->Stop();
	m_startResetBtn->SetLabelText( "Start" );
	m_iconizeOnTimerTick = false;
	if (m_pTaskBarIcon)
	{
		m_pTaskBarIcon->SetIcon(wxIcon(hourglass), wxString::Format(wxT("%02i:%02i:%02i"), m_hours, m_minutes, m_seconds));
	}
}

void TimerTrayMainFrame::ToggleTimer()
{
	ReloadTimer();

	if (m_pTimer->IsRunning() == false && ( m_hours != 0 || m_minutes != 0 || m_seconds != 0 ) )
	{
		StartTimer();
	}
	else
	{
		StopTimer();
	}
}

bool TimerTrayMainFrame::Countdown()
{
	m_seconds--;
	if ( m_seconds < 0 )
	{
		m_seconds = 59;
		m_minutes--;
		if ( m_minutes < 0 )
		{
			m_minutes = 59;
			m_hours--;
			if ( m_hours < 0 )
			{
				m_hours = 0;
			}
		}
	}

	if ( m_hours == 0 && m_minutes == 0 && m_seconds == 0 )
	{
		return true;
	}

	return false;
}

void TimerTrayMainFrame::TimerElapsed() const
{
	if (m_pTaskBarIcon)
	{
		m_pTaskBarIcon->ShowBalloon("TimerTray", "Countdown finished!");
	}

	wxSound::Play( "Alarm.wav" );
}

void TimerTrayMainFrame::ReloadTimer()
{
	m_hoursCb->GetValue().ToLong( &m_hours );
	m_minutesCb->GetValue().ToLong( &m_minutes );
	m_secondsCb->GetValue().ToLong( &m_seconds );

	UpdateLabel();
}

void TimerTrayMainFrame::UpdateLabel() const
{
	m_countDownLbl->SetLabelText( wxString::Format( wxT( "%02i:%02i:%02i" ), m_hours, m_minutes, m_seconds ) );
}

void TimerTrayMainFrame::UpdateNotificationToolTip() const
{
	if (m_pTaskBarIcon)
	{
		if (m_showIconInverted)
		{
			m_pTaskBarIcon->SetIcon(wxIcon(hourglass_inverted), wxString::Format(wxT("%02i:%02i:%02i"), m_hours, m_minutes, m_seconds));
		}
		else
		{
			m_pTaskBarIcon->SetIcon(wxIcon(hourglass), wxString::Format(wxT("%02i:%02i:%02i"), m_hours, m_minutes, m_seconds));
		}
	}
}

void TimerTrayMainFrame::OnTimer( wxTimerEvent& event )
{
	if ( Countdown() == true )
	{
		wxLogDebug( "Timer elapsed" );
		StopTimer();
		UpdateLabel();
		m_showIconInverted = false;
		UpdateNotificationToolTip();
		ReloadTimer();
		TimerElapsed();
		return;
	}

	UpdateNotificationToolTip();
	UpdateLabel();
	m_showIconInverted = !m_showIconInverted;

	if ( IsIconized() == false && m_iconizeOnTimerTick == true )
	{
		Hide();
		m_iconizeOnTimerTick = false;
	}
}

void TimerTrayMainFrame::OnStartResetBtnClicked( wxCommandEvent& event )
{
	ToggleTimer();

	event.Skip();
}

void TimerTrayMainFrame::OnHoursSelected( wxCommandEvent& event )
{
	if (m_pTimer->IsRunning() )
	{
		StopTimer();
		ReloadTimer();
	}

	ReloadTimer();

	UpdateLabel();

	event.Skip();
}

void TimerTrayMainFrame::OnMinutesSelected( wxCommandEvent& event )
{
	if (m_pTimer->IsRunning() )
	{
		StopTimer();
		ReloadTimer();
	}

	ReloadTimer();

	UpdateLabel();

	event.Skip();
}

void TimerTrayMainFrame::OnSecondsSelected( wxCommandEvent& event )
{
	if (m_pTimer->IsRunning() )
	{
		StopTimer();
		ReloadTimer();
	}

	ReloadTimer();
	
	UpdateLabel();

	event.Skip();
}




