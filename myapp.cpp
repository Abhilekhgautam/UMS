#include "myapp.h"
#include "searchframe.h"
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
 searchFrame* frame = new searchFrame();
 
 frame->Show(true);
 SetTopWindow(frame); 
 return true;
}
