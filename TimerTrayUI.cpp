///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "TimerTrayUI.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );


	bSizer2->Add( 0, 0, 1, 0, 0 );

	m_countDownLbl = new wxStaticText( this, wxID_ANY, wxT("00:00:00"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_countDownLbl->Wrap( -1 );
	m_countDownLbl->SetFont( wxFont( 40, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Verdana") ) );

	bSizer2->Add( m_countDownLbl, 1, wxALIGN_CENTER, 0 );


	bSizer2->Add( 0, 0, 1, 0, 0 );


	bSizer1->Add( bSizer2, 7, wxEXPAND, 0 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	m_hoursCb = new wxComboBox( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 55,-1 ), 0, NULL, wxCB_READONLY );
	bSizer4->Add( m_hoursCb, 0, wxALL, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Hours"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer4->Add( m_staticText2, 0, wxEXPAND|wxLEFT, 5 );


	bSizer3->Add( bSizer4, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	m_minutesCb = new wxComboBox( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 55,-1 ), 0, NULL, wxCB_READONLY );
	bSizer5->Add( m_minutesCb, 0, wxALL, 5 );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Minutes"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer5->Add( m_staticText3, 0, wxEXPAND|wxLEFT, 5 );


	bSizer3->Add( bSizer5, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	m_secondsCb = new wxComboBox( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 55,-1 ), 0, NULL, wxCB_READONLY );
	bSizer6->Add( m_secondsCb, 0, wxALL, 5 );

	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Seconds"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer6->Add( m_staticText4, 0, wxEXPAND|wxLEFT, 5 );


	bSizer3->Add( bSizer6, 1, wxEXPAND, 5 );

	m_startResetBtn = new wxButton( this, wxID_ANY, wxT("Start"), wxDefaultPosition, wxSize( 81,34 ), 0 );
	bSizer3->Add( m_startResetBtn, 0, wxALL, 5 );


	bSizer1->Add( bSizer3, 0, wxEXPAND, 0 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_ACTIVATE, wxActivateEventHandler( MainFrame::OnActivate ) );
	m_hoursCb->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MainFrame::OnHoursSelected ), NULL, this );
	m_minutesCb->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MainFrame::OnMinutesSelected ), NULL, this );
	m_secondsCb->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MainFrame::OnSecondsSelected ), NULL, this );
	m_startResetBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnStartResetBtnClicked ), NULL, this );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_ACTIVATE, wxActivateEventHandler( MainFrame::OnActivate ) );
	m_hoursCb->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MainFrame::OnHoursSelected ), NULL, this );
	m_minutesCb->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MainFrame::OnMinutesSelected ), NULL, this );
	m_secondsCb->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MainFrame::OnSecondsSelected ), NULL, this );
	m_startResetBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnStartResetBtnClicked ), NULL, this );

}

AboutDlg::AboutDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* m_pMainSizer;
	m_pMainSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	m_stopwatchBmp = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_stopwatchBmp->SetMaxSize( wxSize( 191,130 ) );

	bSizer8->Add( m_stopwatchBmp, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 15 );


	m_pMainSizer->Add( bSizer8, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("TimerTray"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText5->Wrap( -1 );
	m_staticText5->SetFont( wxFont( 28, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer9->Add( m_staticText5, 0, wxALL|wxEXPAND, 5 );

	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("(c) 2022 BigPilot"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer9->Add( m_staticText6, 5, wxALIGN_CENTER_HORIZONTAL|wxTOP, 5 );

	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Licensed under the GPLv3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer9->Add( m_staticText7, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxLEFT|wxRIGHT, 5 );


	bSizer9->Add( 0, 0, 1, wxEXPAND, 5 );

	m_versionLbl = new wxStaticText( this, wxID_ANY, wxT("Version 2.0.0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_versionLbl->Wrap( -1 );
	m_versionLbl->SetFont( wxFont( 10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer9->Add( m_versionLbl, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	bSizer9->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button2 = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_button2, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	bSizer9->Add( 0, 0, 1, wxEXPAND, 5 );


	m_pMainSizer->Add( bSizer9, 0, wxEXPAND, 5 );


	this->SetSizer( m_pMainSizer );
	this->Layout();
	m_pMainSizer->Fit( this );

	this->Centre( wxBOTH );
}

AboutDlg::~AboutDlg()
{
}
