#include "myframe.h"
#include <wx/sizer.h>

myFrame::myFrame(const wxString& title)
          :wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(250, 250), wxMAXIMIZE | wxDEFAULT_FRAME_STYLE){

  wxButton* addUser = new wxButton(this, wxID_ANY, "Add a new User", wxDefaultPosition, wxSize(400, 70));
  wxButton* deleteUser = new wxButton(this, wxID_ANY, "Delete a User", wxDefaultPosition, wxSize(400, 70));
  wxButton* searchUser = new wxButton(this, wxID_ANY, "Search a User", wxDefaultPosition, wxSize(400, 70));
 
  wxBoxSizer* button_sizer = new wxBoxSizer(wxVERTICAL);
  
  button_sizer->AddStretchSpacer(1);
  button_sizer->Add(addUser, 0,  wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL);
  button_sizer->Add(deleteUser, 0, wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL);  
  button_sizer->Add(searchUser, 0, wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL);
  button_sizer->AddStretchSpacer(1); 

  SetSizerAndFit(button_sizer);

  Centre();

}

