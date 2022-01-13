#include <wx/grid.h>
#include <wx/wx.h>

class umsTable : public wxGrid{
 int r,c;

//void onCellClick(wxGridEvent& event);

// wxDECLARE_EVENT_TABLE();
 public:
  umsTable(wxWindow*,int rows, int cols);
  void createTable();
};
