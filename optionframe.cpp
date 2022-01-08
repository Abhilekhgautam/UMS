#include "optionframe.h"
#include "searchframe.h"
#include "userdialog.h"
#include <wx/sizer.h>
#include <wx/colour.h>
//main frame of app that is parent of every window/frames

//frame responsible to display options (buttons) to the users
optionFrame::optionFrame()
          :wxFrame(nullptr, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxMAXIMIZE | wxDEFAULT_FRAME_STYLE){
  
  wxBitmap image;
  image.LoadFile("./media/ums_banner_large.png");
  wxStaticBitmap* banner = new wxStaticBitmap(this, wxID_ANY, image);

  // Buttons 
  wxButton* addUser = new wxButton(this, 5, "Add User", wxDefaultPosition, wxSize(400, 70));
  wxButton* deleteUser = new wxButton(this, 6, "Delete  User", wxDefaultPosition, wxSize(400, 70));
  wxButton* searchUser = new wxButton(this, 7, "Search  User", wxDefaultPosition, wxSize(400, 70));
  wxButton* updateUser = new wxButton(this, 8, "Update  User", wxDefaultPosition, wxSize(400,70)); 
  wxButton* exit = new wxButton(this, 9, "Exit", wxDefaultPosition, wxSize(400,70));
  wxBoxSizer* option_sizer = new wxBoxSizer(wxVERTICAL);

 // Center the button in the frame 
  option_sizer->Add(banner, 1, wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL);
  
  option_sizer->Add(addUser, 0,  wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL);
  option_sizer->Add(updateUser, 0, wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL);
  option_sizer->Add(deleteUser, 0, wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL);  
  option_sizer->Add(searchUser, 0, wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL);
  option_sizer->Add(exit, 0, wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL);
  option_sizer->AddStretchSpacer(1); 
  
// auto adjust the size of the sizer
  SetSizerAndFit(option_sizer);

  SetBackgroundColour(wxT("black"));  
 
  Centre();
// set icon in the taskbar

  SetIcon(wxIcon("./media/ums1.png"));
}

void optionFrame::addUserClick(wxCommandEvent& event){
 /*
  TODO: open the dialog box to add Users
 */
  userDialog* addUser = new userDialog("Add User", this);
}

void optionFrame::searchUserClick(wxCommandEvent& event){
/*
  TODO: open a search user frame
*/
  searchFrame* searchUser = new searchFrame("Search", this);
  searchUser->Show();
}

void optionFrame::updateUserClick(wxCommandEvent& event){
  
/*
  TODO: open the dialog box to update User
*/

 searchFrame* updateUser = new searchFrame("Update", this);
 updateUser->Show();

}

void optionFrame::deleteUserClick(wxCommandEvent& event){

/*
  TODO: open a search frame that alows the user to be deleted
*/
 searchFrame* deleteUser = new searchFrame("Delete", this);
 deleteUser->Show();
}

void optionFrame::exit(wxCommandEvent& event){

 Close(true);

}

void optionFrame::quit(wxCloseEvent& event){

 wxMessageDialog* quitWarn = new wxMessageDialog(this, wxT("Are you sure, you want to Quit"), wxT("Quit"), wxOK | wxCANCEL);

 if(quitWarn->ShowModal() == wxID_OK)
   Destroy();

}
 wxBEGIN_EVENT_TABLE(optionFrame, wxFrame)
  EVT_BUTTON(5,optionFrame::addUserClick)
  EVT_BUTTON(6, optionFrame::deleteUserClick)
  EVT_BUTTON(7, optionFrame::searchUserClick)
  EVT_BUTTON(8,optionFrame::updateUserClick)
  EVT_BUTTON(9, optionFrame::exit)
  EVT_CLOSE(optionFrame::quit)
wxEND_EVENT_TABLE()
