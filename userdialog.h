#pragma once
#include <wx/wx.h>

class userDialog : public wxDialog{
 
 private:
  void onAddUser(wxCommandEvent& event);
  void onSelectImage(wxCommandEvent& event);
  void onSetDefault(wxCommandEvent& event);
  void onCancel(wxCommandEvent& event);
  void onQuit(wxCloseEvent& event);  

  wxBitmap pp;
  wxStaticBitmap* profile;  
  wxPanel* panel;
  wxStaticBox* image;
  wxTextCtrl* name_text;
  wxTextCtrl* email_text;
  wxTextCtrl* address_text;
  wxTextCtrl* phone_text;
  wxRadioButton* gen_male;
  wxRadioButton* gen_female;
  wxRadioButton* gen_others;
  wxDECLARE_EVENT_TABLE();
 public:
  userDialog(const wxString &Title, wxWindow* parent);
  wxPanel* imagePanel;
  void setProfile(wxString filename);  

};
