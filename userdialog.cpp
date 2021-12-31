#include <wx/image.h>
#include "userdialog.h"


userDialog::userDialog(const wxString& Title)
           : wxDialog(nullptr, -1, Title, wxDefaultPosition, wxSize(850, 850)){
 
 wxImage::AddHandler( new wxPNGHandler);
 wxImage::AddHandler(new wxJPEGHandler);

 wxPanel* panel = new wxPanel(this, -1);
 wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
 wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

 wxStaticBox* name = new wxStaticBox(panel, -1, wxT("Full Name"), wxPoint(15,5), wxSize(250,100));

 wxStaticBox* image = new wxStaticBox(panel, -1, wxT("Image"), wxPoint(280, 5), wxSize(200,200));
 wxButton* add_img = new wxButton(panel, 1, wxT("Select"), wxPoint(340, 80), wxSize(70,30)); 
 

 wxTextCtrl* name_text = new wxTextCtrl(panel, -1, wxEmptyString,  wxPoint(20,20), wxSize(230, 80));

 wxStaticBox* email = new wxStaticBox(panel,-1,wxT("Email"),wxPoint(15, 105), wxSize(250,100));
 wxTextCtrl* email_text = new wxTextCtrl(panel, -1, wxEmptyString,  wxPoint(20,120), wxSize(230, 80));


 wxStaticBox* address = new wxStaticBox(panel,-1,wxT("Address"),wxPoint(15, 205),wxSize(250,100));
 wxTextCtrl* address_text = new wxTextCtrl(panel, -1, wxEmptyString,  wxPoint(20,220), wxSize(230, 80));

 wxStaticBox* phone = new wxStaticBox(panel, -1 , wxT("Phone"), wxPoint(280, 205 ), wxSize(250,100));

 wxTextCtrl* phone_text = new wxTextCtrl(panel, -1, wxEmptyString, wxPoint(290, 220), wxSize(230,80)); 

 wxStaticBox* gender = new wxStaticBox(panel, -1, wxT("Gender"), wxPoint(15, 305), wxSize(250,100));
  
  wxRadioButton* gen_male = new wxRadioButton(panel, -1, 
      wxT("Male"), wxPoint(15, 325));
  wxRadioButton* gen_female = new wxRadioButton(panel, -1, 
      wxT("Female"), wxPoint(15, 345));
  wxRadioButton *gen_others = new wxRadioButton(panel, -1, 
      wxT("Others"), wxPoint(15, 365));



 wxButton* addButton = new wxButton(this, 2, wxT("Add"), wxDefaultPosition, wxSize(70, 30));

 wxButton* cancelButton = new wxButton (this, 3, wxT("Cancel"), wxDefaultPosition, wxSize(70, 30));

 hbox->Add(addButton, 1);
 hbox->Add(cancelButton, 1, wxLeft, 5);

 vbox->Add(panel, 1);
 vbox->Add(hbox, 0 , wxALIGN_CENTER | wxTOP | wxBOTTOM , 10); 

 SetSizer(vbox);

 Centre();
 ShowModal();
 
 Destroy();

}

wxBEGIN_EVENT_TABLE(userDialog, wxDialog)
   EVT_BUTTON(1, userDialog::onSelectImage)
   EVT_BUTTON(2, userDialog::onAddUser)
   EVT_BUTTON(3, userDialog::onCancel)
 wxEND_EVENT_TABLE()


void userDialog::onCancel(wxCommandEvent& event){
  wxMessageDialog* dialog = new wxMessageDialog(this, wxT("No user will be added,Are you sure to continue?"), wxT("Question"), wxOK | wxCANCEL);

if(dialog->ShowModal() == wxID_OK)
  Close(true);

}

void userDialog::onAddUser(wxCommandEvent& event){
 wxMessageDialog* dialog = new wxMessageDialog(this, wxT("A new user will be added"), wxT("Question"), wxOK | wxCANCEL);
 dialog->ShowModal();
  
}

void userDialog::onSelectImage(wxCommandEvent& event){
 //to do: view the selected image
 
 wxFileDialog* selectFile = new wxFileDialog(this, "Select an Image","","", "*.png");
 
 
 selectFile->ShowModal();
}
