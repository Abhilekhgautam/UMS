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
 imagePanel = new wxPanel(this, -1, wxPoint (285, 25),wxSize(190,175));
 

 name_text = new wxTextCtrl(panel, -1, wxEmptyString,  wxPoint(20,20), wxSize(230, 80));

 wxStaticBox* email = new wxStaticBox(panel,-1,wxT("Email"),wxPoint(15, 105), wxSize(250,100));
 email_text = new wxTextCtrl(panel, -1, wxEmptyString,  wxPoint(20,120), wxSize(230, 80));


 wxStaticBox* address = new wxStaticBox(panel,-1,wxT("Address"),wxPoint(15, 205),wxSize(250,100));
address_text = new wxTextCtrl(panel, -1, wxEmptyString,  wxPoint(20,220), wxSize(230, 80));

 wxStaticBox* phone = new wxStaticBox(panel, -1 , wxT("Phone"), wxPoint(280, 205 ), wxSize(250,100));

phone_text = new wxTextCtrl(panel, -1, wxEmptyString, wxPoint(290, 220), wxSize(230,80)); 

 wxStaticBox* gender = new wxStaticBox(panel, -1, wxT("Gender"), wxPoint(15, 305), wxSize(250,100));
  
 gen_male = new wxRadioButton(panel, -1, 
      wxT("Male"), wxPoint(15, 325));
 gen_female = new wxRadioButton(panel, -1, 
      wxT("Female"), wxPoint(15, 345));
 gen_others = new wxRadioButton(panel, -1, 
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
/*
  TODO:1.Check if all the textbox are filled
       2.Minor check for email 'check for @ and . symbol'
       3.Check the length of phone number
*/

//check if all text box are filled at least!
  if(name_text->GetLineLength(0) < 1 || email_text->GetLineLength(0) < 1 || address_text->GetLineLength(0) < 1){
    wxMessageDialog* error_dialog = new wxMessageDialog(this, wxT("All the input fields are necessary"), wxT("Error"), wxOK | wxICON_ERROR);
    error_dialog->ShowModal();
    return;
 }

 //check if email has a '@' and '.' symbol
  wxString check_email =  email_text->GetLineText(0);
  int count = 0;
  int len = 0;
 for(char elt : check_email){
   if(elt == '@' || elt == '.') count ++;
   len ++;
 }
 
 if(count != 2 || len < 8 ){
  wxMessageDialog* error_dialog = new wxMessageDialog(this, wxT(" Your email is invalid "), wxT("Error"), wxOK | wxICON_ERROR);
    error_dialog->ShowModal();
    return;

 }

//check if phone number has 10 digits
/*
  TODO: Check if all the input characters are integer
*/
  if(phone_text->GetLineLength(0) != 10){
  
 wxMessageDialog* error_dialog = new wxMessageDialog(this, wxT(" Your phone number is invalid "), wxT("Error"), wxOK | wxICON_ERROR);
    error_dialog->ShowModal();
    return;

 }  
// Informs the user that if everything goes well a new user will be added
 wxMessageDialog* dialog = new wxMessageDialog(this, wxT("A new user will be added"), wxT("Question"), wxOK | wxCANCEL);
 if(dialog->ShowModal() == wxOK){
  /*
    TODO: 1. Call the User's C'tor to create a new user
          2. Add the new data to the file
          3. Check if the data is successfully added to the file in case of failure inform the user about failure
          4. Informs the user that a user has been successfully added to the file
          5. Clear all the input field
  */ 
 } 
}

void userDialog::onSelectImage(wxCommandEvent& event){

 
   wxFileDialog* selectFile = new wxFileDialog(this, "Select an Image","","", "*.png");
   if(selectFile->ShowModal() == 5100){
     wxString file_path = selectFile->GetPath();
    /*
        
       TODO: display the selected image
   */
  }
   
}
