// Author: Rachael Judy
// Date: 3/31/2020
// Purpose: Generates GUI for cache simulator


///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "CacheGUI.h"

///////////////////////////////////////////////////////////////////////////

CacheGUI::CacheGUI( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* ButtonAndCacheSizer;
	ButtonAndCacheSizer = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* cacheDisplaySizer;
	cacheDisplaySizer = new wxGridSizer( 0, 3, 0, 0 );
	
	m_staticText26 = new wxStaticText( this, wxID_ANY, wxT("Enter a two digit decimal address between 00 and 63:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	cacheDisplaySizer->Add( m_staticText26, 0, wxALL, 5 );
	
	
	cacheDisplaySizer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	cacheDisplaySizer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	inputText = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	inputText->SetMaxLength( 2 ); 
	cacheDisplaySizer->Add( inputText, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	resultLabel = new wxStaticText( this, wxID_ANY, wxT("Hit or Miss?"), wxDefaultPosition, wxDefaultSize, 0 );
	resultLabel->Wrap( -1 );
	cacheDisplaySizer->Add( resultLabel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	cacheDisplaySizer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	searchButton = new wxButton( this, wxID_ANY, wxT("Search Cache"), wxDefaultPosition, wxDefaultSize, 0 );
	cacheDisplaySizer->Add( searchButton, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_button2 = new wxButton( this, wxID_ANY, wxT("Reset Cache"), wxDefaultPosition, wxDefaultSize, 0 );
	cacheDisplaySizer->Add( m_button2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	ButtonAndCacheSizer->Add( cacheDisplaySizer, 1, wxEXPAND, 20 );
	
	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer( 0, 3, 2, 0 );
	
	
	gSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Tag"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	m_staticText2->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	gSizer2->Add( m_staticText2, 0, wxALL, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Data"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	m_staticText3->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	gSizer2->Add( m_staticText3, 0, wxALL, 5 );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Set 00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	gSizer2->Add( m_staticText4, 0, wxALL, 5 );
	
	tag000 = new wxStaticText( this, wxID_ANY, wxT("____"), wxDefaultPosition, wxDefaultSize, 0 );
	tag000->Wrap( -1 );
	gSizer2->Add( tag000, 0, wxALL, 5 );
	
	data000 = new wxStaticText( this, wxID_ANY, wxT("__"), wxDefaultPosition, wxDefaultSize, 0 );
	data000->Wrap( -1 );
	gSizer2->Add( data000, 0, wxALL, 5 );
	
	
	gSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	tag001 = new wxStaticText( this, wxID_ANY, wxT("____"), wxDefaultPosition, wxDefaultSize, 0 );
	tag001->Wrap( -1 );
	gSizer2->Add( tag001, 0, wxALL, 5 );
	
	data001 = new wxStaticText( this, wxID_ANY, wxT("__"), wxDefaultPosition, wxDefaultSize, 0 );
	data001->Wrap( -1 );
	gSizer2->Add( data001, 0, wxALL, 5 );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Set 01"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	gSizer2->Add( m_staticText9, 0, wxALL, 5 );
	
	tag010 = new wxStaticText( this, wxID_ANY, wxT("____"), wxDefaultPosition, wxDefaultSize, 0 );
	tag010->Wrap( -1 );
	gSizer2->Add( tag010, 0, wxALL, 5 );
	
	data010 = new wxStaticText( this, wxID_ANY, wxT("__"), wxDefaultPosition, wxDefaultSize, 0 );
	data010->Wrap( -1 );
	gSizer2->Add( data010, 0, wxALL, 5 );
	
	
	gSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	tag011 = new wxStaticText( this, wxID_ANY, wxT("____"), wxDefaultPosition, wxDefaultSize, 0 );
	tag011->Wrap( -1 );
	gSizer2->Add( tag011, 0, wxALL, 5 );
	
	data011 = new wxStaticText( this, wxID_ANY, wxT("__"), wxDefaultPosition, wxDefaultSize, 0 );
	data011->Wrap( -1 );
	gSizer2->Add( data011, 0, wxALL, 5 );
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("Set 10"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	gSizer2->Add( m_staticText14, 0, wxALL, 5 );
	
	tag100 = new wxStaticText( this, wxID_ANY, wxT("____"), wxDefaultPosition, wxDefaultSize, 0 );
	tag100->Wrap( -1 );
	gSizer2->Add( tag100, 0, wxALL, 5 );
	
	data100 = new wxStaticText( this, wxID_ANY, wxT("__"), wxDefaultPosition, wxDefaultSize, 0 );
	data100->Wrap( -1 );
	gSizer2->Add( data100, 0, wxALL, 5 );
	
	
	gSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	tag101 = new wxStaticText( this, wxID_ANY, wxT("____"), wxDefaultPosition, wxDefaultSize, 0 );
	tag101->Wrap( -1 );
	gSizer2->Add( tag101, 0, wxALL, 5 );
	
	data101 = new wxStaticText( this, wxID_ANY, wxT("__"), wxDefaultPosition, wxDefaultSize, 0 );
	data101->Wrap( -1 );
	gSizer2->Add( data101, 0, wxALL, 5 );
	
	m_staticText20 = new wxStaticText( this, wxID_ANY, wxT("Set 11"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	gSizer2->Add( m_staticText20, 0, wxALL, 5 );
	
	tag110 = new wxStaticText( this, wxID_ANY, wxT("____"), wxDefaultPosition, wxDefaultSize, 0 );
	tag110->Wrap( -1 );
	gSizer2->Add( tag110, 0, wxALL, 5 );
	
	data110 = new wxStaticText( this, wxID_ANY, wxT("__"), wxDefaultPosition, wxDefaultSize, 0 );
	data110->Wrap( -1 );
	gSizer2->Add( data110, 0, wxALL, 5 );
	
	
	gSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	tag111 = new wxStaticText( this, wxID_ANY, wxT("____"), wxDefaultPosition, wxDefaultSize, 0 );
	tag111->Wrap( -1 );
	gSizer2->Add( tag111, 0, wxALL, 5 );
	
	data111 = new wxStaticText( this, wxID_ANY, wxT("__"), wxDefaultPosition, wxDefaultSize, 0 );
	data111->Wrap( -1 );
	gSizer2->Add( data111, 0, wxALL, 5 );
	
	
	gSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	gSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	gSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	ButtonAndCacheSizer->Add( gSizer2, 2, wxEXPAND, 10 );
	
	this->SetSizer( ButtonAndCacheSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	searchButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CacheGUI::searchCache ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CacheGUI::resetCache ), NULL, this );
}

CacheGUI::~CacheGUI()
{
	// Disconnect Events
	searchButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CacheGUI::searchCache ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CacheGUI::resetCache ), NULL, this );
	
}
