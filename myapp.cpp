#include "myapp.h"
#include "optionframe.h"
#include <wx/utils.h>   
#include <wx/splash.h>
wxIMPLEMENT_APP(myapp);

bool myapp:: OnInit(){
 wxBitmap bitmap;

 if (bitmap.LoadFile("./media/ums_icon.png", wxBITMAP_TYPE_PNG)){
    wxSplashScreen* splash = new wxSplashScreen(bitmap,
        wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
        3000, NULL, -1, wxDefaultPosition, wxDefaultSize,
        wxBORDER_SIMPLE|wxSTAY_ON_TOP);

}
 wxYield();
 sleep(2);
 optionFrame* options = new optionFrame("UMS");
 
 options->Show(true);
 SetTopWindow(options); 
 return true;
}
