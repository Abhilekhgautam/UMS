#include "searchframe.h"
#include <wx/sizer.h>
#include <wx/dcclient.h>
#include "userdialog.h"

searchFrame :: searchFrame()
             : wxFrame(nullptr, wxID_ANY, "" , wxDefaultPosition, wxSize(240, 250), wxDEFAULT_FRAME_STYLE | wxMAXIMIZE){

  wxGridSizer* my_sizer = new wxGridSizer(1, 4, 0, 1);

 wxTextCtrl* text_box = new wxTextCtrl(this, -1, wxEmptyString, wxDefaultPosition, wxSize(400, 30), wxTE_CAPITALIZE | wxTE_PROCESS_ENTER);

 wxButton* search_button = new wxButton(this, wxID_ANY, "Search", wxDefaultPosition, wxDefaultSize);

 my_sizer->AddStretchSpacer(1);
 my_sizer->Add(text_box, 1, wxALIGN_CENTER_VERTICAL);
 my_sizer->Add(search_button , 1, wxALIGN_CENTER_VERTICAL);
 my_sizer->AddStretchSpacer(1);

 SetSizerAndFit(my_sizer);
  SetIcon(wxIcon("./media/ums1.png")); 
  Center();
  
 userDialog* new_dialog = new userDialog("Add");

}

