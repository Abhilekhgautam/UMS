#include "searchdialog.h"

/*
 This is a test class to simulate the backend action which similar to the
  backend's User class
*/
class testUser{
public:
 wxString id, name, gender, email, phone, address;

   testUser(){}
   testUser(wxString i, wxString n, wxString g, wxString e, wxString p, wxString add){
      id = i;
      name = n;
      gender = g;
      email = e;
      phone = p;
      address = add;
  }

};

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

    //For this make a default Constructor of User class
    User usr = new User();    

    // call the function to search for the user

    //sth should be a arr of User like object
    sth = usr.displayUser(search_txt);

    //if no user found inform the user about it
    if(sth == NULL || sth == 0){
   
      wxMessageDialog* message = new wxMessageDialog(this, "No User Found", "Error", wxOK);
       if(message->ShowModal() == wxID_OK) return;
    
   }
 */



/*

  TODO: 1. noRows = getNoRows(search_txt);
        
        2.Use a for loop to assign the values to array of users

*/

// Backend simulation begins here
  int noRows = 2; //assign its value by calling the getNoRows function

// use a for loop here to assign the values to array
  testUser user[noRows] = {
                       testUser("191304","Abhilekh Gautam", "Male","abhilekhgautam119@gmail.com","9867399695","Kathmandu"),
                       testUser("191309", "Ankit Lamichhane", "Male", "ankitlamichhane5@gmail.com","9825415054","Biratnagar")
                      };

// Backend simulation ends here
  std::string users[noRows][6];


// Assigns the user value to the array
for(int i = 0 ; i < noRows ; i++){

  users[i][0] = user[i].id;
  users[i][1] = user[i].name;
  users[i][2] = user[i].gender;
  users[i][3] = user[i].email;
  users[i][4] = user[i].phone;
  users[i][5] = user[i].address;


}



 // call the table's C'tor
   umsTable* dataTable = new umsTable(this, noRows , 6);
   dataTable->CreateGrid(noRows, 6);
   dataTable->createTable();

// Write the data to the table returned value 

  for(int i = 0 ; i < noRows ; i++){
   for(int j = 0; j < 6; j++){
    
     dataTable->SetCellValue(i,j,users[i][j]);  
   
   } 
 }

 // Refresh the sizer  
   vbox->Layout();
   vbox->Add(dataTable, 0,wxALL | wxALIGN_CENTER );
   vbox->Layout(); 
  
}


 wxBEGIN_EVENT_TABLE(searchDialog, wxDialog)
  EVT_BUTTON(99, searchDialog::onButtonClick)
 wxEND_EVENT_TABLE()

