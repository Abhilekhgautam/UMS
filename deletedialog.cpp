#include "wx/wx.h"
#include "deletedialog.h"

#ifndef testUser_h
  #define testUser_h

    class testUser{
      public:
     wxString id, name, gender, email, phone, address, path;

       testUser();
       testUser(wxString i, wxString n, wxString g, wxString e, wxString p, wxString add, wxString image_path);

    };


#endif

deleteDialog :: deleteDialog (wxWindow* parent, testUser& usr, wxString title)
              : updateDialog(parent, title,  usr){



}

void deleteDialog :: showDialog(){

 ShowModal();

}

void deleteDialog :: onButtonClick(wxCommandEvent& event){

  wxMessageDialog* message = new wxMessageDialog(this, "Delete this User?","Confirm",wxOK | wxCANCEL);
  if(message -> ShowModal() == wxID_OK)
    Destroy();
  
}

void deleteDialog :: onCancel(wxCommandEvent& event){

 wxMessageDialog* warning = new wxMessageDialog(this, "No User will be deleted", "Confirm", wxOK | wxCANCEL);
 warning->ShowModal();
  Destroy();
}
