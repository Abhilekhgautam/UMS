#pragma once
#include <wx/wx.h>
class searchFrame : public wxFrame{

 private:
  void onSearchClick(wxCommandEvent& event);
  void onExit(wxCommandEvent& event); 
  wxDECLARE_EVENT_TABLE();

 public:
  searchFrame();
  void drawTable(int row, int col);
 
};
