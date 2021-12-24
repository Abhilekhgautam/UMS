#include "myapp.h"
#include "optionframe.h"
#include <wx/utils.h>   
#include <wx/splash.h>
wxIMPLEMENT_APP(myapp);

bool myapp:: OnInit(){
 wxBitmap bitmap;

 if (bitmap.LoadFile("presplash.png", wxBITMAP_TYPE_PNG))
{
    wxSplashScreen* splash = new wxSplashScreen(bitmap,
        wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
        6000, NULL, -1, wxDefaultPosition, wxDefaultSize,
        wxBORDER_SIMPLE|wxSTAY_ON_TOP);
}
wxYield();
 optionFrame* options = new optionFrame("");
 
 options->Show(true);
 SetTopWindow(options); 
 return true;
}
