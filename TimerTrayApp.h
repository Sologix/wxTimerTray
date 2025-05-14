#ifndef _MAIN_H_
#define _MAIN_H_
#ifdef __WXMSW__
#include <wx/msw/msvcrt.h>      // redefines the new() operator 
#endif
#include <wx/wx.h>
#include <wx/snglinst.h>
#include "TimerTrayMainFrame.h"

class TimerTrayApp : public wxApp
{
  public:
    bool OnInit(void) wxOVERRIDE;
	int OnExit(void)  wxOVERRIDE;
	
  protected:
	TimerTrayMainFrame* m_pMainFrame = nullptr;
	wxSingleInstanceChecker* m_pChecker = nullptr;
};

DECLARE_APP(TimerTrayApp)

#endif
