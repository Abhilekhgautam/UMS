#pragma once
#include <wx/wx.h>
#include "umstable.h"

class searchDialog : public wxDialog{
  wxTextCtrl* searchBox;
  wxButton* searchButton;
  wxBoxSizer* vbox;
  wxBoxSizer* hbox;
  

  wxDECLARE_EVENT_TABLE();
 public:
  searchDialog(wxWindow* , wxString);
  void showDialog();

  void onButtonClick(wxCommandEvent& event); 
};
