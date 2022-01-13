#include "updatedialog.h"
#include "searchdialog.h"

#ifndef testUser_h
  #define testUser_h
     
    class testUser{
      public:
     wxString id, name, gender, email, phone, address, path;
   
       testUser();
       testUser(wxString i, wxString n, wxString g, wxString e, wxString p, wxString add, wxString image_path);
   
    };
         
 
#endif
 searchDialog :: searchDialog(wxWindow* parent, wxString Title)
              : wxDialog(parent, wxID_ANY, Title, wxDefaultPosition, wxSize(900,900)){

 searchBox = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(250, 30));
 searchButton = new wxButton(this, 99, "Search", wxDefaultPosition, wxSize(80,30)); 


  // sizers 
  vbox = new wxBoxSizer(wxVERTICAL);
  hbox = new wxBoxSizer(wxHORIZONTAL);


//Add button and searchbox to the sizer
 hbox->Add(searchBox, 0 , wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL);
 hbox->Add(searchButton, 0, wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL);

 vbox->Add(hbox, 0 , wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
 SetSizer(vbox);
}

//Displays this dialog box

 void searchDialog :: showDialog(){
  ShowModal();
 }

//Event Handler for the button click event

void searchDialog :: onButtonClick(wxCommandEvent& event){
  if(searchBox->GetLineLength(0) == 0){
    wxMessageDialog* message = new wxMessageDialog(this, "Search Field cannot be empty", "Error", wxOK);
   if(message->ShowModal() == wxID_OK)
     return;
 }

 /*
   TODO:Call the backend function and get the number of users.

    std::string search_txt =  searchBox->GetLineText(0).mb_str();

    User usr;   

    // call the function to search for the user

    //sth should be a arr of User like object
     bool sth = usr.isPresent(search_txt);

    //if no user found inform the user about it
    if(!sth){
   
      wxMessageDialog* message = new wxMessageDialog(this, "No User Found", "Error", wxOK);
       if(message->ShowModal() == wxID_OK) return;
    
   }

   RData returnedUser = usr.displayUser(search_txt);
 */

 testUser abhi = testUser("191304","Abhilekh Gautam", "Male", "abhilekhgautam119@gmail.com","9867399695","Kathmandu","./media/my_pp.jpg");
 updateDialog* update = new updateDialog(this, "Update", abhi);
 update->showDialog();
  
 
}


 wxBEGIN_EVENT_TABLE(searchDialog, wxDialog)
  EVT_BUTTON(99, searchDialog::onButtonClick)
 wxEND_EVENT_TABLE()

