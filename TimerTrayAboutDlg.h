#ifndef __TimerTrayAboutDlg__
#define __TimerTrayAboutDlg__
#ifdef __WXMSW__
#include <wx/msw/msvcrt.h>      // redefines the new() operator 
#endif
#include <wx/wx.h>
#include "TimerTrayUI.h"

class TimerTrayAboutDlg : public AboutDlg
{
	public:
		TimerTrayAboutDlg( wxWindow* parent );

		void SetAboutBitmap( const wxBitmap& bitmap );
};

#endif // __TimerTrayAboutDlg__
