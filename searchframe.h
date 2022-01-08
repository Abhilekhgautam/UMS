#pragma once
#include <wx/grid.h>
#include <wx/wx.h>
class searchFrame : public wxFrame{

 private:
  wxGrid* my_grid;
  wxBoxSizer* vbox;
  wxBoxSizer* hbox;

  void onSearchClick(wxCommandEvent& event);
  void onExit(wxCommandEvent& event); 
  wxDECLARE_EVENT_TABLE();

 public:
  searchFrame(const wxString& Title, wxWindow* parent);
  void showframe();
  void drawTable(int row, int col);
  
};
