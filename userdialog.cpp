#include "userdialog.h"

userDialog::userDialog(const wxString& Title)
           : wxDialog(nullptr, -1, Title, wxDefaultPosition, wxSize(850, 850)){

 wxPanel* panel = new wxPanel(this, -1);
 wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
 wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

 wxStaticBox* name = new wxStaticBox(panel, -1, wxT("Full Name"), wxPoint(15,5), wxSize(250,100));

 wxStaticBox* image = new wxStaticBox(panel, -1, wxT("Image"), wxPoint(280, 5), wxSize(210,200));
 wxTextCtrl* name_text = new wxTextCtrl(panel, -1, wxEmptyString,  wxPoint(20,20), wxSize(200, 80));

 wxStaticBox* email = new wxStaticBox(panel,-1,wxT("Email"),wxPoint(15, 105), wxSize(250,100));
 wxTextCtrl* email_text = new wxTextCtrl(panel, -1, wxEmptyString,  wxPoint(20,120), wxSize(200, 80));


 wxStaticBox* address = new wxStaticBox(panel,-1,wxT("Address"),wxPoint(15, 205),wxSize(250,100));
 wxTextCtrl* address_text = new wxTextCtrl(panel, -1, wxEmptyString,  wxPoint(20,220), wxSize(200, 80));

 wxStaticBox* phone = new wxStaticBox(panel, -1 , wxT("Phone"), wxPoint(280, 205 ), wxSize(250,100));

 wxTextCtrl* phone_text = new wxTextCtrl(panel, -1, wxEmptyString, wxPoint(290, 220), wxSize(200,80)); 

 wxStaticBox* gender = new wxStaticBox(panel, -1, wxT("Gender"), wxPoint(15, 305), wxSize(250,100));
  
  wxRadioButton* gen_male = new wxRadioButton(panel, -1, 
      wxT("Male"), wxPoint(15, 325));
  wxRadioButton* gen_female = new wxRadioButton(panel, -1, 
      wxT("Female"), wxPoint(15, 345));
  wxRadioButton *gen_others = new wxRadioButton(panel, -1, 
      wxT("Others"), wxPoint(15, 365));



wxButton* addButton = new wxButton(this, -1, wxT("Add"), wxDefaultPosition, wxSize(70, 30));

wxButton* cancelButton = new wxButton (this, -1, wxT("Cancel"), wxDefaultPosition, wxSize(70, 30));

hbox->Add(addButton, 1);
hbox->Add(cancelButton, 1, wxLeft, 5);

vbox->Add(panel, 1);
vbox->Add(hbox, 0 , wxALIGN_CENTER | wxTOP | wxBOTTOM , 10); 

SetSizer(vbox);

Centre();
ShowModal();

Destroy();

}
