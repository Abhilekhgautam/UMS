#include "searchdialog.h"

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
 void searchDialog :: showDialog(){
  ShowModal();
 }

void searchDialog :: onButtonClick(wxCommandEvent& event){
  if(searchBox->GetLineLength(0) == 0){
    wxMessageDialog* message = new wxMessageDialog(this, "Search Field cannot be empty", "Error", wxOK);
   if(message->ShowModal() == wxID_OK)
     return;
 }

 /*
   TODO:Call the backend function and get the number of users.
 
 */
 
 // call the table's C'tor
   umsTable* dataTable = new umsTable(this, 1, 5);

// if users are found assign it to 
/*
  for(int i = 1 ; i <= 1 ; i++){
   for(int j = 1; j <= 5; j++){
    
     dataTable->SetCellValue(i,j)  
   
   } 
 }
*/
 // Refresh the sizer  
   vbox->Layout();
   vbox->Add(dataTable, 0,wxALL | wxALIGN_CENTER );
   vbox->Layout(); 
  
}


 wxBEGIN_EVENT_TABLE(searchDialog, wxDialog)
  EVT_BUTTON(99, searchDialog::onButtonClick)
 wxEND_EVENT_TABLE()

