#include <wx/wx.h>
#include "updatedialog.h"


//This is just a test class to simulate database connection

#ifndef testUser_h
  #define testUser_h

    class testUser{
      public:
     wxString id, name, gender, email, phone, address, path;

       testUser();
       testUser(wxString i, wxString n, wxString g, wxString e, wxString p, wxString add, wxString image_path);

    };


#endif


class deleteDialog : public updateDialog{

  void onBtnClick(wxCommandEvent& event);
  void onCancel(wxCommandEvent& event);

 public:
   deleteDialog(wxWindow* parent, testUser& usr, wxString title);//TODO: change the second parameter to backend class which is equivalent to testUser
   void showDialog();
};
