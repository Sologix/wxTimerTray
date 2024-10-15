#ifdef __WXMSW__
#include <wx/msw/msvcrt.h>      // redefines the new() operator 
#endif
#include "TimerTrayAboutDlg.h"

TimerTrayAboutDlg::TimerTrayAboutDlg( wxWindow* parent ) : AboutDlg( parent )
{

}

void TimerTrayAboutDlg::SetAboutBitmap(const wxBitmap& bitmap)
{
	m_stopwatchBmp->SetBitmap( bitmap );

	GetSizer()->Layout();
	GetSizer()->Fit( this );
}
