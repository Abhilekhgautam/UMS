#include <wx/wx.h>
#include "searchdialog.h"

class deleteFrame : public searchDialog{

 public:
   deleteFrame(wxWindow* parent);
   void onButtonClick(wxCommandEvent& event);
   void showDialog();
};
