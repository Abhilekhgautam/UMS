#include "myapp.h"
#include "optionframe.h"
#include "searchdialog.h"
#include <wx/utils.h>   
#include <wx/splash.h>
wxIMPLEMENT_APP(myapp);

bool myapp:: OnInit(){
 wxInitAllImageHandlers();
 wxBitmap bitmap;

 if (bitmap.LoadFile("./media/ums_icon.png", wxBITMAP_TYPE_PNG)){
    wxSplashScreen* splash = new wxSplashScreen(bitmap,
        wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
        3000, NULL, -1, wxDefaultPosition, wxDefaultSize,
        wxBORDER_SIMPLE|wxSTAY_ON_TOP);

}
 wxYield();
 sleep(3);
 optionFrame* landingFrame = new optionFrame();
 
 landingFrame->Show(true);
 SetTopWindow(landingFrame); 
 return true;
}
