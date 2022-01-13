#pragma once
#include <wx/wx.h>

class searchDialog : public wxDialog{

 protected:
  wxTextCtrl* searchBox;
  wxButton* searchButton;
  wxBoxSizer* vbox;
  wxBoxSizer* hbox;

  wxDECLARE_EVENT_TABLE();
 public:
  searchDialog(wxWindow* , wxString);
  virtual void showDialog();
  
  virtual void onButtonClick(wxCommandEvent& event); 
};
