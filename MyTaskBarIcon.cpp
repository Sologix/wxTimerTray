#include <wx/wx.h>
#include <wx/menu.h>
#include "MyTaskbarIcon.h"
#include "TimerTrayAboutDlg.h"
#include "Images/Stopwatch.xpm"

extern wxIcon g_Icon;

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

MyTaskBarIcon::~MyTaskBarIcon()
{
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

void MyTaskBarIcon::SetMainFrame(TimerTrayMainFrame* pMainFrame)
{
    m_pMainFrame = pMainFrame;
}

void MyTaskBarIcon::OnMenuAbout( wxCommandEvent& )
{
    TimerTrayAboutDlg* pAboutDlg = new TimerTrayAboutDlg( m_pMainFrame );

	auto image = wxBitmap(Stopwatch).ConvertToImage();
    if (image.IsOk() )
    {
        image.Rescale( 130, 249 );

        pAboutDlg->SetAboutBitmap( wxBitmap( image ) );
    }

    pAboutDlg->SetIcon( g_Icon );
    pAboutDlg->Layout();
    pAboutDlg->ShowModal();

    pAboutDlg->Destroy();
    delete pAboutDlg;
}

void MyTaskBarIcon::OnMenuExit( wxCommandEvent& )
{
    m_pMainFrame->Destroy();
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