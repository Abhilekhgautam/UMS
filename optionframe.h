#pragma once

#include <wx/wx.h>

class optionFrame : public wxFrame{

 wxDECLARE_EVENT_TABLE();
 void addUserClick(wxCommandEvent& event);
 void searchUserClick(wxCommandEvent& event);
 void updateUserClick(wxCommandEvent& event);
 void deleteUserClick(wxCommandEvent& event);
 void exit(wxCommandEvent& event);
 void quit(wxCloseEvent& event);
  public:
   optionFrame();
};
