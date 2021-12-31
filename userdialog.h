#pragma once
#include <wx/wx.h>

class userDialog : public wxDialog{
 
 private:
  void onAddUser(wxCommandEvent& event);
  void onSelectImage(wxCommandEvent& event);
  void onCancel(wxCommandEvent& event);
  wxTextCtrl* name_text;
  wxTextCtrl* email_text;
  wxTextCtrl* address_text;
  wxTextCtrl* phone_text;
  wxRadioButton* gen_male;
  wxRadioButton* gen_female;
  wxRadioButton* gen_others;
  wxDECLARE_EVENT_TABLE();
 public:
  userDialog(const wxString &Title);
  wxPanel* imagePanel;  

};
