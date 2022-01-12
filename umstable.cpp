#include "umstable.h"

umsTable :: umsTable(wxWindow* parent, int rows, int cols)
          : wxGrid(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize){

  r = rows;
  c = cols;    


}

void umsTable :: createTable(){

 
    SetColLabelValue(0, "ID");
    SetColLabelValue(1, "Name");
    SetColLabelValue(2, "Gender");
    SetColLabelValue(3, "Email");
    SetColLabelValue(4, "Phone");
    SetColLabelValue(5, "Address");

    SetLabelBackgroundColour(wxT("black"));
    SetColSize(0,70);
    SetColSize(1,150);
    SetColSize(2,70);
    SetColSize(3,220);
    SetColSize(4,90);
    SetColSize(5, 150);

}
