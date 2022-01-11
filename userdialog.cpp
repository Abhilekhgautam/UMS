// #include "User.h"
#include <wx/image.h>
#include <wx/valnum.h>
#include "userdialog.h"
#include "UHandle.h"

userDialog::userDialog(const wxString& Title, wxWindow* parent)
           : wxDialog(parent, -1, Title, wxDefaultPosition, wxSize(530,500)){
//Creates a Bitmap for the user's profile picture
 pp = wxBitmap(wxSize(200,190));

//initially load the default image for the profile picture
 pp.LoadFile(wxT("./media/default_pp.jpg"));
 unsigned long m_value = 98; 

//Validator for the phone number input
  wxIntegerValidator<unsigned long>
   val(&m_value, wxNUM_VAL_THOUSANDS_SEPARATOR);

 panel = new wxPanel(this, -1);
 wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
 wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

// Input fields start here
 wxStaticBox* name = new wxStaticBox(panel, -1, wxT("Full Name"), wxPoint(15,5), wxSize(250,100));

//select image interface
 image = new wxStaticBox(panel, -1, wxT("Image"), wxPoint(280, 5), wxSize(200,230));
 profile = new wxStaticBitmap (panel, wxID_ANY, pp, wxPoint(280,25),wxSize(200,190));
 wxButton* select = new wxButton(panel ,1, wxT("Select"), wxPoint(285, 215), wxSize(70,30));
 wxButton* set_default = new wxButton(panel , 4, wxT("Set default"), wxPoint(365, 215), wxSize(90,30));

// name input field
 name_text = new wxTextCtrl(panel, -1, wxEmptyString,  wxPoint(20,20), wxSize(230, 80));


 wxStaticBox* email = new wxStaticBox(panel,-1,wxT("Email"),wxPoint(15, 105), wxSize(250,100));
 email_text = new wxTextCtrl(panel, -1, wxEmptyString,  wxPoint(20,120), wxSize(230, 80));


 wxStaticBox* address = new wxStaticBox(panel,-1,wxT("Address"),wxPoint(15, 205),wxSize(250,100));
 address_text = new wxTextCtrl(panel, -1, wxEmptyString,  wxPoint(20,220), wxSize(230, 80));

 wxStaticBox* phone = new wxStaticBox(panel, -1 , wxT("Phone"), wxPoint(280, 255 ), wxSize(250,100));

phone_text = new wxTextCtrl(panel, -1, wxEmptyString, wxPoint(290, 245), wxSize(230,100), 0, val); 

 wxStaticBox* gender = new wxStaticBox(panel, -1, wxT("Gender"), wxPoint(15, 305), wxSize(250,100));
  

//Radio button for gender Selection
 gen_male = new wxRadioButton(panel, -1, 
      wxT("Male"), wxPoint(15, 325));
 gen_female = new wxRadioButton(panel, -1, 
      wxT("Female"), wxPoint(15, 345));
 gen_others = new wxRadioButton(panel, -1, 
      wxT("Others"), wxPoint(15, 365));

//Input field ends here


 wxButton* addButton = new wxButton(this, 2, wxT("Add"), wxDefaultPosition, wxSize(70, 30));

 wxButton* cancelButton = new wxButton (this, 3, wxT("Cancel"), wxDefaultPosition, wxSize(70, 30));

 hbox->Add(addButton, 1);
 hbox->Add(cancelButton, 1, wxLeft, 5);

//Add the panel to the vertical sizer
 vbox->Add(panel, 1);
 vbox->Add(hbox, 0 , wxALIGN_CENTER | wxTOP | wxBOTTOM , 10); 

 SetSizer(vbox);

//Center the dialogbox
 Centre();

//display the dialogbox
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

//Sets image to the default profile picture

void userDialog::onSetDefault(wxCommandEvent& event){

 setProfile("./media/default_pp.jpg");

}

//Changes the profile Image of the User
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

//Event handler for the exit event
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
 
 if(count < 2 || len < 8 ){
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

//  std::cout<<"Test"<<endl;

 if(dialog->ShowModal() == wxID_OK){
  //  cout<<"Enter ok"<<endl;
  /*
    TODO: 1. Call the User's C'tor to create a new user
          2. Add the new data to the file
          3. Check if the data is successfully added to the file in case of failure inform the user about failure
          4. Informs the user that a user has been successfully added to the file
          5. Clear all the input field
  */
  //*conversion from wxString to string
    std::string name = std::string(name_text->GetLineText(0).mb_str());
    std::string email =  std::string(email_text->GetLineText(0).mb_str());
    std::string address = std::string(address_text->GetLineText(0).mb_str());
    std::string phone = std::string(phone_text->GetLineText(0).mb_str());
    std::string gender = "male";
   

 //call the function to add to the database

 // First call the constructor of User class
  User usr(name, email, address, phone, gender);
 
 // this call should return a success or failure message 
  bool success = usr.addUser();

  // std::cout<<success<<endl;
    // cout<<"Success....."<<endl;
   if(!success){
    
   wxMessageDialog* warning = new wxMessageDialog(this, "Cannot add User", "Error", wxOK);
   if(warning->ShowModal() == wxID_OK)
     return;
  }

  else{
    wxMessageDialog* success = new wxMessageDialog(this, "User Added Successfully", "Success", wxOK);
       if(success->ShowModal() == wxID_OK){
        //destroys the addUser dialog
         Destroy();
    }  
   }
   
 } 
}

/*
  Responsible for the image selection process from the device 

*/

void userDialog::onSelectImage(wxCommandEvent& event){

 
   wxFileDialog* selectFile = new wxFileDialog(this, "Select an Image","","", "`PNG and JPEG files (*.png; *jpg)|*.png;*.jpg");
  if(selectFile->ShowModal() == 5100){
     wxString file_path = selectFile->GetPath();
    

  //Provides the preview selected image feature
   
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
