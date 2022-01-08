#include <wx/image.h>
#include <wx/valnum.h>
#include "userdialog.h"


userDialog::userDialog(const wxString& Title, wxWindow* parent)
           : wxDialog(parent, -1, Title, wxDefaultPosition, wxSize(530,500)){
//Creates a Bitmap for the user's profile picture
 pp = wxBitmap(wxSize(200,190));

//initially load the default image for the profile picture
 pp.LoadFile(wxT("./media/default_pp.jpg"));
 unsigned long m_value = 98; 

  wxIntegerValidator<unsigned long>
   val(&m_value, wxNUM_VAL_THOUSANDS_SEPARATOR);

  panel = new wxPanel(this, -1);
 wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
 wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

 wxStaticBox* name = new wxStaticBox(panel, -1, wxT("Full Name"), wxPoint(15,5), wxSize(250,100));

 image = new wxStaticBox(panel, -1, wxT("Image"), wxPoint(280, 5), wxSize(200,230));
 profile = new wxStaticBitmap (panel, wxID_ANY, pp, wxPoint(280,25),wxSize(200,190));
 wxButton* select = new wxButton(panel ,1, wxT("Select"), wxPoint(285, 215), wxSize(70,30));
 wxButton* set_default = new wxButton(panel , 4, wxT("Set default"), wxPoint(365, 215), wxSize(90,30));

 name_text = new wxTextCtrl(panel, -1, wxEmptyString,  wxPoint(20,20), wxSize(230, 80));

 wxStaticBox* email = new wxStaticBox(panel,-1,wxT("Email"),wxPoint(15, 105), wxSize(250,100));
 email_text = new wxTextCtrl(panel, -1, wxEmptyString,  wxPoint(20,120), wxSize(230, 80));


 wxStaticBox* address = new wxStaticBox(panel,-1,wxT("Address"),wxPoint(15, 205),wxSize(250,100));
 address_text = new wxTextCtrl(panel, -1, wxEmptyString,  wxPoint(20,220), wxSize(230, 80));

 wxStaticBox* phone = new wxStaticBox(panel, -1 , wxT("Phone"), wxPoint(280, 255 ), wxSize(250,100));

phone_text = new wxTextCtrl(panel, -1, wxEmptyString, wxPoint(290, 245), wxSize(230,100), 0, val); 

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
   EVT_BUTTON(4, userDialog::onSetDefault)
   EVT_CLOSE(userDialog::onQuit)
 wxEND_EVENT_TABLE()

void userDialog::onSetDefault(wxCommandEvent& event){

 setProfile("./media/default_pp.jpg");

}

void userDialog::setProfile(wxString filename){
 pp = wxBitmap(wxSize(200,190));
 if(pp.LoadFile(filename)){
   if (pp.GetHeight() > 210 || pp.GetWidth() > 210){
    wxMessageDialog* dialog = new wxMessageDialog(this, wxT("Image too large, 200 px image is required"), wxT("Image too large"), wxOK);
    if(dialog->ShowModal() == wxID_OK){
      return;
    }
  }
 }
 profile->SetBitmap(pp);

}

void userDialog::onQuit(wxCloseEvent& event){
 
 wxMessageDialog* quitWarn = new wxMessageDialog(this, wxT("No user will be added,Do you want to Continue?"),wxT("Exit"), wxOK | wxCANCEL);

 if(quitWarn->ShowModal() == wxID_OK)
   Destroy();   
}

void userDialog::onCancel(wxCommandEvent& event){
  wxMessageDialog* dialog = new wxMessageDialog(this, wxT("No user will be added,Are you sure to continue?"), wxT("Exit"), wxOK | wxCANCEL);

if(dialog->ShowModal() == wxID_OK)
  Destroy();

}

void userDialog::onAddUser(wxCommandEvent& event){
/*
  Functionality:1.Check if all the textbox are filled
       2.Minor check for email 'check for @ and . symbol'
       3.Check the length of phone number
*/

//check if all text box are filled at least!
  if(name_text->GetLineLength(0) < 1 || email_text->GetLineLength(0) < 1 || address_text->GetLineLength(0) < 1 || phone_text->GetLineLength(0) < 1){
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

//check if phone number is valid
/*
  TODO: Check if all the input characters are integer
*/
  if(phone_text->GetLineLength(0) != 10){
  
 wxMessageDialog* error_dialog = new wxMessageDialog(this, wxT(" Your phone number is invalid "), wxT("Error"), wxOK | wxICON_ERROR);
    error_dialog->ShowModal();
    return;

 }  
// Informs the user that if everything goes well a new user will be added
 wxMessageDialog* dialog = new wxMessageDialog(this, wxT("A new user will be added"), wxT("Confirm"), wxOK | wxCANCEL);
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

 
   wxFileDialog* selectFile = new wxFileDialog(this, "Select an Image","","", "`PNG and JPEG files (*.png; *jpg)|*.png;*.jpg");
  if(selectFile->ShowModal() == 5100){
     wxString file_path = selectFile->GetPath();
    /*
        
       
   Function: displays the selected image
   */
  wxBitmap pp;
 if(pp.LoadFile(file_path)){
   if (pp.GetHeight() > 210 || pp.GetWidth() > 210){
    wxMessageDialog* dialog = new wxMessageDialog(this, wxT("Image too large, 200 px image is required"), wxT("Image too large"), wxOK);
    if(dialog->ShowModal() == wxID_OK){
      return;
    }
  }
 }

  profile->SetBitmap(pp); 

  }
}
