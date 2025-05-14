#ifdef __WXMSW__
#include <wx/msw/msvcrt.h>      // redefines the new() operator 
#endif
#include <wx/wx.h>
#include <wx/menu.h>
#include "MyTaskbarIcon.h"
#include "TimerTrayAboutDlg.h"
#include "Images/Stopwatch.xpm"
#include "Images/hourglass.xpm"

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

MyTaskBarIcon::MyTaskBarIcon(TimerTrayMainFrame* pMainFrame) : m_pMainFrame(pMainFrame)
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


void MyTaskBarIcon::ShowMainFrame() const
{
    if (m_pMainFrame)
    {
        m_pMainFrame->Raise();
        m_pMainFrame->Show(true);
    }
}

void MyTaskBarIcon::OnMenuAbout( wxCommandEvent& )
{
    TimerTrayAboutDlg* pAboutDlg = new TimerTrayAboutDlg(m_pMainFrame);

	auto image = wxBitmap(Stopwatch).ConvertToImage();
    if (image.IsOk() )
    {
        image.Resize( wxSize(191, 130), wxPoint(0,0) );

        pAboutDlg->SetAboutBitmap( wxBitmap( image ) );
    }

    pAboutDlg->SetIcon(wxIcon(hourglass));
    pAboutDlg->Layout();
    pAboutDlg->ShowModal();

    delete pAboutDlg;
}

void MyTaskBarIcon::OnMenuExit( wxCommandEvent& )
{
    if (m_pMainFrame)
    {
        m_pMainFrame->Close(true);
    }
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