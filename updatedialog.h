#include "userdialog.h"
#include <wx/wx.h>

//A class just for the simulation of database connection
#ifndef testUser_h
  #define testUser_h

    class testUser{
      public:
     wxString id, name, gender, email, phone, address, path;

       testUser();
       testUser(wxString i, wxString n, wxString g, wxString e, wxString p, wxString add, wxString image_path);

    };


#endif

class updateDialog : public userDialog{

virtual void onBtnClick(wxCommandEvent& event);
void onCancel(wxCommandEvent& event);

 public:
  updateDialog(wxWindow* parent,wxString Title, testUser&);//TODO:change the third parameter to backend's class equivalent to testUser
 virtual void showDialog();

};
