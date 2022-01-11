#include <wx/grid.h>
#include <wx/wx.h>

class umsTable : public wxGrid{
 int r,c;
 public:
  umsTable(wxWindow*,int rows, int cols);

};
