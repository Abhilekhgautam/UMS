#include "myapp.h"
#include "myframe.h"

wxIMPLEMENT_APP(myapp);

bool myapp:: OnInit(){
 myFrame* frame = new myFrame ("");
 
 frame->Show(true);
 return true;
}
