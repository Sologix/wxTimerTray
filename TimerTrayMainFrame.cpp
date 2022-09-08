#include <wx/wx.h>
#include <wx/log.h>
#include <wx/event.h>
#include <wx/sound.h>
#include <wx/config.h>
#include "TimerTrayMainFrame.h"
#include "MyTaskbarIcon.h"

extern wxIcon g_Icon;

TimerTrayMainFrame::TimerTrayMainFrame( wxWindow* parent ) : MainFrame( parent ), m_timer( new wxTimer() )
{
	m_notificationMessage = new wxNotificationMessage( "TimerTray", "Countdown finished!" );

	SetIcon( g_Icon );

	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( TimerTrayMainFrame::OnClose ) );

	m_timer->SetOwner( this );
	this->Connect( wxEVT_TIMER, wxTimerEventHandler( TimerTrayMainFrame::OnTimer ) );

	FillComboBoxValues();

	LoadLastTimerSetting();

	ReloadTimer();

	CreateTaskBarIcon();
}

TimerTrayMainFrame::~TimerTrayMainFrame()
{
	SaveLastTimerSetting();

	m_taskBarIcon->Destroy();
	
	delete m_timer;
	delete m_notificationMessage;
	this->Disconnect( wxEVT_TIMER, wxTimerEventHandler( TimerTrayMainFrame::OnTimer ) );

	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( TimerTrayMainFrame::OnClose ) );
}

void TimerTrayMainFrame::OnClose( wxCloseEvent& event )
{
	Hide();
}

void TimerTrayMainFrame::CreateTaskBarIcon()
{
    m_taskBarIcon = new MyTaskBarIcon();

    if ( m_taskBarIcon->SetIcon( g_Icon,"00:00:00" ) == false )
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

	m_taskBarIcon->SetMainFrame(this);
}

void TimerTrayMainFrame::LoadLastTimerSetting() const
{
	wxConfig* config = new wxConfig( "TimerTray" );

	m_hoursCb->SetSelection( config->ReadLong( "Hours", 0 ) );
	m_minutesCb->SetSelection( config->ReadLong( "Minutes", 0 ) );
	m_secondsCb->SetSelection( config->ReadLong( "Seconds", 0 ) );

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
	m_timer->Start( 1000 );
	m_startResetBtn->SetLabelText( "Reset" );
	m_iconizeOnTimerTick = true;
}

void TimerTrayMainFrame::StopTimer()
{
	m_timer->Stop();
	m_startResetBtn->SetLabelText( "Start" );
	m_iconizeOnTimerTick = false;
}

void TimerTrayMainFrame::ToggleTimer()
{
	ReloadTimer();

	if ( m_timer->IsRunning() == false && ( m_hours != 0 || m_minutes != 0 || m_seconds != 0 ) )
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
	m_notificationMessage->Show();

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

void TimerTrayMainFrame::UpdateNotificationToolTip()
{
	m_taskBarIcon->SetIcon( g_Icon, wxString::Format( wxT( "%02i:%02i:%02i" ), m_hours, m_minutes, m_seconds ) );
}

void TimerTrayMainFrame::OnTimer( wxTimerEvent& event )
{
	if ( Countdown() == true )
	{
		wxLogDebug( "Timer elapsed" );
		StopTimer();
		UpdateLabel();
		UpdateNotificationToolTip();
		ReloadTimer();
		TimerElapsed();
		return;
	}

	UpdateNotificationToolTip();
	UpdateLabel();

	if ( IsIconized() == false && m_iconizeOnTimerTick == true )
	{
		Hide();
		m_iconizeOnTimerTick = false;
	}
}

void TimerTrayMainFrame::OnStartResetBtnClicked( wxCommandEvent& event )
{
	ToggleTimer();

	MainFrame::OnStartResetBtnClicked( event );
}

void TimerTrayMainFrame::OnHoursSelected( wxCommandEvent& event )
{
	if ( m_timer->IsRunning() )
	{
		StopTimer();
		ReloadTimer();
	}

	ReloadTimer();

	UpdateLabel();

	MainFrame::OnHoursSelected( event );
}

void TimerTrayMainFrame::OnMinutesSelected( wxCommandEvent& event )
{
	if ( m_timer->IsRunning() )
	{
		StopTimer();
		ReloadTimer();
	}

	ReloadTimer();

	UpdateLabel();

	MainFrame::OnMinutesSelected( event );
}

void TimerTrayMainFrame::OnSecondsSelected( wxCommandEvent& event )
{
	if ( m_timer->IsRunning() )
	{
		StopTimer();
		ReloadTimer();
	}

	ReloadTimer();
	
	UpdateLabel();

	MainFrame::OnSecondsSelected( event );
}




