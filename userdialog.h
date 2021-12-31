#pragma once
#include <wx/wx.h>

class userDialog : public wxDialog{
 
 private:
  void onAddUser(wxCommandEvent& event);
  void onSelectImage(wxCommandEvent& event);
  void onCancel(wxCommandEvent& event);

  wxDECLARE_EVENT_TABLE();
 public:
  userDialog(const wxString &Title);

};
