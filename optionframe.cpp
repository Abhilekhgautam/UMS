#include "optionframe.h"
#include <wx/sizer.h>

//frame responsible to display options (buttons) to the users
optionFrame::optionFrame(const wxString& title)
          :wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(250, 250), wxMAXIMIZE | wxDEFAULT_FRAME_STYLE){

  // Buttons 
  wxButton* addUser = new wxButton(this, wxID_ANY, "Add a new User", wxDefaultPosition, wxSize(400, 70));
  wxButton* deleteUser = new wxButton(this, wxID_ANY, "Delete a User", wxDefaultPosition, wxSize(400, 70));
  wxButton* searchUser = new wxButton(this, wxID_ANY, "Search a User", wxDefaultPosition, wxSize(400, 70));
 
  wxBoxSizer* button_sizer = new wxBoxSizer(wxVERTICAL);
 
 // Center the button in the frame 
  button_sizer->AddStretchSpacer(1);
  button_sizer->Add(addUser, 0,  wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL);
  button_sizer->Add(deleteUser, 0, wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL);  
  button_sizer->Add(searchUser, 0, wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL);
  button_sizer->AddStretchSpacer(1); 
  
// auto adjust the size of the sizer
  SetSizerAndFit(button_sizer);

  Centre();
// set icon in the taskbar

  SetIcon(wxIcon("./media/ums1.png"));
}

