#pragma once
#include <wx/wx.h>

class userDialog : public wxDialog{
 
 protected:
  virtual void onBtnClick(wxCommandEvent& event);
  void onSelectImage(wxCommandEvent& event);
  void onSetDefault(wxCommandEvent& event);
  virtual void onCancel(wxCommandEvent& event);
  void onQuit(wxCloseEvent& event);  

  wxFileDialog* selectFile;
  wxString file_path;
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
  void setProfile(wxString filename);
  void setTextValue(std::string name, std::string gender, std::string email, std::string phone, std::string address, std::string path);  
  void showDialog();
};
