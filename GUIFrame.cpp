///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "GUIFrame.h"

///////////////////////////////////////////////////////////////////////////

GUIFrame::GUIFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxColour( 0, 128, 128 ) );
	
	mbar = new wxMenuBar( 0 );
	fileMenu = new wxMenu();
	wxMenuItem* m_menuItem3;
	m_menuItem3 = new wxMenuItem( fileMenu, idMenuCalc, wxString( wxT("&Izračunaj") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( m_menuItem3 );
	
	wxMenuItem* menuFileQuit;
	menuFileQuit = new wxMenuItem( fileMenu, idMenuQuit, wxString( wxT("&Prekini") ) + wxT('\t') + wxT("Alt+F4"), wxT("Quit the application"), wxITEM_NORMAL );
	fileMenu->Append( menuFileQuit );
	
	mbar->Append( fileMenu, wxT("&Izbornik") ); 
	
	helpMenu = new wxMenu();
	wxMenuItem* menuHelpAbout;
	menuHelpAbout = new wxMenuItem( helpMenu, idMenuAbout, wxString( wxT("&O programu") ) + wxT('\t') + wxT("F1"), wxT("Show info about this application"), wxITEM_NORMAL );
	helpMenu->Append( menuHelpAbout );
	
	mbar->Append( helpMenu, wxT("&Pomoć") ); 
	
	this->SetMenuBar( mbar );
	
	statusBar = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	wxBoxSizer* glavniSizer;
	glavniSizer = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Parametri") ), wxHORIZONTAL );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Rata"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	m_staticText1->SetMinSize( wxSize( 75,-1 ) );
	
	bSizer2->Add( m_staticText1, 0, wxALL, 5 );
	
	txtRata = new wxTextCtrl( sbSizer1->GetStaticBox(), ID_RATA, wxT("10"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	txtRata->SetMinSize( wxSize( 100,-1 ) );
	
	bSizer2->Add( txtRata, 0, wxALL, 5 );
	
	m_staticText2 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Max. nabava"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	m_staticText2->SetMinSize( wxSize( 70,-1 ) );
	
	bSizer2->Add( m_staticText2, 0, wxALL, 5 );
	
	txtMaxKol = new wxTextCtrl( sbSizer1->GetStaticBox(), ID_MAX_KOL, wxT("70"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	txtMaxKol->SetMinSize( wxSize( 100,-1 ) );
	
	bSizer2->Add( txtMaxKol, 0, wxALL, 5 );
	
	
	bSizer7->Add( bSizer2, 0, 0, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText4 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Troškovi skl."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	m_staticText4->SetMinSize( wxSize( 75,-1 ) );
	
	bSizer3->Add( m_staticText4, 0, wxALL, 5 );
	
	txtTrosSkl = new wxTextCtrl( sbSizer1->GetStaticBox(), ID_TROSKOVI_SKL, wxT("5"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	txtTrosSkl->SetMinSize( wxSize( 100,-1 ) );
	
	bSizer3->Add( txtTrosSkl, 0, wxALL, 5 );
	
	m_staticText5 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Max. zalihe"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	m_staticText5->SetMinSize( wxSize( 70,-1 ) );
	
	bSizer3->Add( m_staticText5, 0, wxALL, 5 );
	
	txtMaxZal = new wxTextCtrl( sbSizer1->GetStaticBox(), ID_MAX_ZAL, wxT("30"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	txtMaxZal->SetMinSize( wxSize( 100,-1 ) );
	
	bSizer3->Add( txtMaxZal, 0, wxALL, 5 );
	
	
	bSizer7->Add( bSizer3, 0, 0, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText6 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Broj razdoblja"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	m_staticText6->SetMinSize( wxSize( 75,-1 ) );
	
	bSizer4->Add( m_staticText6, 0, wxALL, 5 );
	
	txtBrojRazd = new wxTextCtrl( sbSizer1->GetStaticBox(), ID_BROJ_RAZDOBLJA, wxT("3"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	txtBrojRazd->SetMinSize( wxSize( 100,-1 ) );
	
	bSizer4->Add( txtBrojRazd, 0, wxALL, 5 );
	
	m_staticText3 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Troškovi nab."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer4->Add( m_staticText3, 0, wxALL, 5 );
	
	txtTrosNab = new wxTextCtrl( sbSizer1->GetStaticBox(), ID_TROSKOVI_NAB, wxT("800"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	txtTrosNab->SetMinSize( wxSize( 100,-1 ) );
	
	bSizer4->Add( txtTrosNab, 0, wxALL, 5 );
	
	
	bSizer7->Add( bSizer4, 0, 0, 5 );
	
	
	sbSizer1->Add( bSizer7, 0, wxEXPAND|wxRIGHT, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText8 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Potražnja"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer5->Add( m_staticText8, 0, wxALL, 5 );
	
	gridPotraznja = new wxGrid( sbSizer1->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	gridPotraznja->CreateGrid( 3, 1 );
	gridPotraznja->EnableEditing( true );
	gridPotraznja->EnableGridLines( true );
	gridPotraznja->EnableDragGridSize( false );
	gridPotraznja->SetMargins( 0, 0 );
	
	// Columns
	gridPotraznja->EnableDragColMove( false );
	gridPotraznja->EnableDragColSize( true );
	gridPotraznja->SetColLabelSize( 20 );
	gridPotraznja->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	gridPotraznja->EnableDragRowSize( true );
	gridPotraznja->SetRowLabelSize( 80 );
	gridPotraznja->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	gridPotraznja->SetDefaultCellAlignment( wxALIGN_RIGHT, wxALIGN_CENTRE );
	gridPotraznja->SetMinSize( wxSize( 200,80 ) );
	gridPotraznja->SetMaxSize( wxSize( 200,120 ) );
	
	bSizer5->Add( gridPotraznja, 0, wxALL, 5 );
	
	
	sbSizer1->Add( bSizer5, 0, wxLEFT, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	btnIzracunaj = new wxButton( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Izračunaj"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxNO_BORDER );
	btnIzracunaj->SetForegroundColour( wxColour( 255, 255, 255 ) );
	btnIzracunaj->SetBackgroundColour( wxColour( 0, 0, 128 ) );
	btnIzracunaj->SetMinSize( wxSize( -1,80 ) );
	
	bSizer11->Add( btnIzracunaj, 0, wxALL, 5 );
	
	m_button3 = new wxButton( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Ispis postupka"), wxDefaultPosition, wxDefaultSize, 0|wxNO_BORDER );
	m_button3->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_button3->SetBackgroundColour( wxColour( 1, 44, 243 ) );
	
	bSizer11->Add( m_button3, 0, wxALL, 5 );
	
	
	sbSizer1->Add( bSizer11, 0, wxEXPAND, 5 );
	
	
	sbSizer1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	glavniSizer->Add( sbSizer1, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Rezultati") ), wxVERTICAL );
	
	m_staticText9 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, wxT("Tablica rješenja problema nabave"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	sbSizer2->Add( m_staticText9, 0, wxALL, 5 );
	
	gridRjesenje = new wxGrid( sbSizer2->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	gridRjesenje->CreateGrid( 0, 0 );
	gridRjesenje->EnableEditing( false );
	gridRjesenje->EnableGridLines( true );
	gridRjesenje->EnableDragGridSize( false );
	gridRjesenje->SetMargins( 0, 0 );
	
	// Columns
	gridRjesenje->EnableDragColMove( false );
	gridRjesenje->EnableDragColSize( true );
	gridRjesenje->SetColLabelSize( 30 );
	gridRjesenje->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	gridRjesenje->EnableDragRowSize( true );
	gridRjesenje->SetRowLabelSize( 80 );
	gridRjesenje->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	gridRjesenje->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	gridRjesenje->SetMinSize( wxSize( 760,150 ) );
	
	sbSizer2->Add( gridRjesenje, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText81 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, wxT("Tablica odluke"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText81->Wrap( -1 );
	sbSizer2->Add( m_staticText81, 0, wxALL, 5 );
	
	gridOdluka = new wxGrid( sbSizer2->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	gridOdluka->CreateGrid( 0, 7 );
	gridOdluka->EnableEditing( true );
	gridOdluka->EnableGridLines( true );
	gridOdluka->EnableDragGridSize( false );
	gridOdluka->SetMargins( 0, 0 );
	
	// Columns
	gridOdluka->EnableDragColMove( false );
	gridOdluka->EnableDragColSize( true );
	gridOdluka->SetColLabelSize( 30 );
	gridOdluka->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	gridOdluka->EnableDragRowSize( true );
	gridOdluka->SetRowLabelSize( 80 );
	gridOdluka->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	gridOdluka->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	sbSizer2->Add( gridOdluka, 1, wxALL, 5 );
	
	
	glavniSizer->Add( sbSizer2, 2, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	
	this->SetSizer( glavniSizer );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	this->Connect( m_menuItem3->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::Izracunaj ) );
	this->Connect( menuFileQuit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnQuit ) );
	this->Connect( menuHelpAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnAbout ) );
	txtRata->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIFrame::ParamPromijenjen ), NULL, this );
	txtMaxKol->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIFrame::ParamPromijenjen ), NULL, this );
	txtTrosSkl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIFrame::ParamPromijenjen ), NULL, this );
	txtMaxZal->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIFrame::ParamPromijenjen ), NULL, this );
	txtBrojRazd->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIFrame::ParamPromijenjen ), NULL, this );
	txtTrosNab->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIFrame::ParamPromijenjen ), NULL, this );
	gridPotraznja->Connect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( GUIFrame::GridPotraznjaPromijenjena ), NULL, this );
	btnIzracunaj->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::Izracunaj ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OtvoriDijalogIspisa ), NULL, this );
}

GUIFrame::~GUIFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	this->Disconnect( idMenuCalc, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::Izracunaj ) );
	this->Disconnect( idMenuQuit, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnQuit ) );
	this->Disconnect( idMenuAbout, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnAbout ) );
	txtRata->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIFrame::ParamPromijenjen ), NULL, this );
	txtMaxKol->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIFrame::ParamPromijenjen ), NULL, this );
	txtTrosSkl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIFrame::ParamPromijenjen ), NULL, this );
	txtMaxZal->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIFrame::ParamPromijenjen ), NULL, this );
	txtBrojRazd->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIFrame::ParamPromijenjen ), NULL, this );
	txtTrosNab->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIFrame::ParamPromijenjen ), NULL, this );
	gridPotraznja->Disconnect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( GUIFrame::GridPotraznjaPromijenjena ), NULL, this );
	btnIzracunaj->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::Izracunaj ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OtvoriDijalogIspisa ), NULL, this );
	
}

dlgIspisRacunanja::dlgIspisRacunanja( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	txtIspis = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	txtIspis->SetFont( wxFont( 10, 75, 90, 90, false, wxT("Lucida Console") ) );
	txtIspis->SetForegroundColour( wxColour( 254, 172, 1 ) );
	txtIspis->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer9->Add( txtIspis, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer10->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_button2 = new wxButton( this, wxID_ANY, wxT("Zatvori"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_button2, 0, wxALL, 5 );
	
	
	bSizer9->Add( bSizer10, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer9 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgIspisRacunanja::Zatvori ), NULL, this );
}

dlgIspisRacunanja::~dlgIspisRacunanja()
{
	// Disconnect Events
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgIspisRacunanja::Zatvori ), NULL, this );
	
}
