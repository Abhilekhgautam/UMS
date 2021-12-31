#include "searchframe.h"
#include <wx/sizer.h>
#include <wx/dcclient.h>
#include "userdialog.h"

searchFrame :: searchFrame()
             : wxFrame(nullptr, wxID_ANY, "" , wxDefaultPosition, wxSize(240, 250), wxDEFAULT_FRAME_STYLE | wxMAXIMIZE){
  /*
     TODO:1. Create a good UI
          2. define a drawTable function
          3. Create a button which on click opens the addUser dialog
  */
  wxGridSizer* my_sizer = new wxGridSizer(1, 4, 0, 1);
// Search box
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

wxBEGIN_EVENT_TABLE(searchFrame, wxFrame)
  EVT_BUTTON(1, searchFrame::onSearchClick)
  EVT_MENU(wxID_EXIT, searchFrame::onExit)
wxEND_EVENT_TABLE()

void searchFrame::onSearchClick(wxCommandEvent& event){
 /*
   TODO: call the drawTable function
 */

}

void searchFrame::onExit(wxCommandEvent& event){
 wxMessageDialog* alert = new wxMessageDialog(this, wxT("Are you sure you want to Exit"), wxT("EXIT"), wxOK | wxCANCEL);
  if(alert->ShowModal() ==  wxOK){
    Close(true);
 }
}
