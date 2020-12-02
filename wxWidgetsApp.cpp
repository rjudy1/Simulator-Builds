// Author: Rachael Judy
// Date: 3/31/2020
// Purpose:  Template wxWidgets application class header file.  No modification to this file are required
// MODIFICATIONS: Rachael Judy - 3/31/2020

#define FILENAME  "subCacheGUI.h"
#define CLASSNAME  subCacheGUI

#include "wxWidgetsApp.h"
#include FILENAME

IMPLEMENT_APP(wxWidgetsApp)

wxWidgetsApp::wxWidgetsApp()  {
}

wxWidgetsApp::~wxWidgetsApp() {
}

bool wxWidgetsApp::OnInit() {
    CLASSNAME* frame = new CLASSNAME( (wxWindow*)NULL );
    frame ->Show();
    SetTopWindow( frame );
    return true;
}
