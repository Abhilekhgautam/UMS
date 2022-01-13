#include "deleteframe.h"
#include "deletedialog.h"


deleteFrame :: deleteFrame(wxWindow* parent)
             : searchDialog(parent, "Delete"){}

void deleteFrame :: onButtonClick(wxCommandEvent& event){

 if(searchBox ->GetLineLength(0) == 0){
  wxMessageDialog* message = new wxMessageDialog(this,"Search Field cannot be Empty", "Error", wxOK | wxICON_ERROR);
  message->ShowModal();
  return;
 }

  //get the text box item
  std::string search_text = searchBox -> GetLineText(0);
 
  //search if the name is present
   /*

   User usr;
   bool available = usr. isPresent(search_text);
  
   if(!available){
     
     wxMessageDialog* message = new wxMessageDialog(this, "User Not found","Not Found", wxOK | wxICON_CANCEL)
      if(message -> ShowModal () == wxID_OK)
         Destroy();   
  
   }

    //if the user is present take the user's data
       RData userData = usr.displayUser(search_txt);
       
     TODO:1. Pass the data to deletDialog's constructor

      deleteDialog* del = new deleteDialog(this, userData, "Delete");
      del->showDialog();

  */

//Just a simulation of backend code (Delete once backend code executes successfully)
//backend simulation begins here
 testUser abhi = testUser("191304","Abhilekh Gautam", "Male", "abhilekhgautam119@gmail.com","9867399695","Kathmandu","./media/my_pp.jpg");
 deleteDialog* del = new deleteDialog(this, abhi, "Delete");
 del->showDialog();
 
//backend simulation ends here
}

void deleteFrame :: showDialog(){

 ShowModal();

}

