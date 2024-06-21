#include <wx/wx.h>
#include "TimerTrayApp.h"
#include "MyTaskbarIcon.h"

IMPLEMENT_APP( TimerTrayApp )

TimerTrayApp::TimerTrayApp() : m_pMainFrame(nullptr), m_pChecker(nullptr)
{
}

bool TimerTrayApp::OnInit()
{
    m_pChecker = new wxSingleInstanceChecker();
    if ( m_pChecker->IsAnotherRunning() == true )
    {
        delete m_pChecker;
        return false;
    }

    wxInitAllImageHandlers();

    if ( !wxTaskBarIcon::IsAvailable() )
    {
        wxMessageBox
        (
            "There appears to be no system tray support in your current environment.",
            "Error",
            wxOK | wxICON_ERROR
        );

        return false;
    }

    m_pMainFrame = new TimerTrayMainFrame(nullptr);

	return true;
}

int TimerTrayApp::OnExit()
{
    delete m_pChecker;

    wxLogDebug("Shutting down");

	return 0;
}


