#include <wx/wx.h>
#include <wx/menu.h>
#include "MyTaskbarIcon.h"
#include "TimerTrayAboutDlg.h"

extern wxIcon* g_Icon;

enum
{
    PU_OPEN = 10001,
    PU_ABOUT,
    PU_EXIT,
};

wxBEGIN_EVENT_TABLE( MyTaskBarIcon, wxTaskBarIcon )
	EVT_MENU( PU_OPEN, MyTaskBarIcon::OnMenuOpen )
	EVT_MENU( PU_ABOUT, MyTaskBarIcon::OnMenuAbout )
	EVT_MENU( PU_EXIT, MyTaskBarIcon::OnMenuExit )
	EVT_TASKBAR_LEFT_DCLICK( MyTaskBarIcon::OnLeftButtonDClick )
wxEND_EVENT_TABLE()

void MyTaskBarIcon::OnLoad()
{
    m_pMainFrame = new TimerTrayMainFrame( nullptr, this );
    m_pAboutDlg = new TimerTrayAboutDlg( m_pMainFrame );
}

void MyTaskBarIcon::OnMenuOpen( wxCommandEvent& )
{
    ShowMainFrame();
}

void MyTaskBarIcon::OnLeftButtonDClick( wxTaskBarIconEvent& )
{
	ShowMainFrame();
}

void MyTaskBarIcon::ShowMainFrame()
{
	m_pMainFrame->Raise();
	m_pMainFrame->Show( true );
}

void MyTaskBarIcon::OnMenuAbout( wxCommandEvent& )
{
	const auto image = new wxImage( wxT("Stopwatch.jpg") );
    if (image->IsOk() )
    {
        image->Rescale( 191, 130 , wxIMAGE_QUALITY_BOX_AVERAGE );

        m_pAboutDlg->SetAboutBitmap( wxBitmap( *image ) );
    }

    delete image;

    m_pAboutDlg->SetIcon( *g_Icon );
    m_pAboutDlg->ShowModal();
    m_pAboutDlg->Layout();
}

void MyTaskBarIcon::OnMenuExit( wxCommandEvent& )
{
    m_pMainFrame->Close( true );
    m_pAboutDlg->Destroy();
    Destroy();
}

wxMenu* MyTaskBarIcon::CreatePopupMenu()
{
	const auto menu = new wxMenu();
    menu->Append( PU_OPEN, "&Open" );
    menu->Append( PU_ABOUT, "&About TimerTray" );
    /* OSX has built-in quit menu for the dock menu, but not for the status item */
#ifdef __WXOSX__
    if ( OSXIsStatusItem() )
#endif
    {
        menu->AppendSeparator();
        menu->Append( PU_EXIT, "E&xit" );
    }

	return menu;
}