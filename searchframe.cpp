#include "searchframe.h"
#include <wx/sizer.h>
#include <wx/dcclient.h>
#include "userdialog.h"
#include <wx/grid.h>

searchFrame :: searchFrame(const wxString& Title, wxWindow* parent)
            : wxFrame(parent, wxID_ANY, Title,  wxDefaultPosition, wxSize(240, 250), wxMAXIMIZE | wxDEFAULT_FRAME_STYLE){
  /*
     TODO:1. Create a good UI
          2. define a drawTable function
          3. Create a button which on click opens the addUser dialog
  */

  // Search box
 wxTextCtrl* text_box = new wxTextCtrl(this, -1, wxEmptyString, wxDefaultPosition, wxSize(400, 30), wxTE_CAPITALIZE | wxTE_PROCESS_ENTER);

 wxButton* search_button = new wxButton(this, wxID_ANY, "Search", wxDefaultPosition, wxSize(70,30));

 
 vbox = new wxBoxSizer(wxVERTICAL);
 hbox = new wxBoxSizer(wxHORIZONTAL);
 my_grid = new wxGrid(this, wxID_ANY);
 


 hbox->AddStretchSpacer(1); 
 hbox->Add(text_box, 1, wxEXPAND);
 hbox->Add(search_button, 0);
 hbox->AddStretchSpacer(1);
 
 vbox->AddStretchSpacer(1);
 vbox->Add(hbox);
 vbox->AddStretchSpacer(2);

 SetSizerAndFit(vbox);


  Center();
  

}

wxBEGIN_EVENT_TABLE(searchFrame, wxFrame) 
 EVT_BUTTON(1, searchFrame::onSearchClick)
 EVT_MENU(wxID_EXIT, searchFrame::onExit)
wxEND_EVENT_TABLE()

void searchFrame::showframe(){
 Show(true);
}

void searchFrame::drawTable(int row, int col){

wxGrid* my_grid = new wxGrid(this, wxID_ANY);

my_grid->CreateGrid(5,5);

}

void searchFrame::onSearchClick(wxCommandEvent& event){
 /*
   TODO: call the drawTable function
 */
 
 my_grid->CreateGrid(1,5);
 my_grid->SetColLabelValue(0,"ID");
 my_grid->SetColLabelValue(1,"Name");
 my_grid->SetColLabelValue(2,"Email");
 my_grid->SetColLabelValue(3,"Phone");
 my_grid->SetColLabelValue(4,"Address"); 

for(int i = 0 ; i < 5 ; i++){
  my_grid->SetColSize(i, 190);
}

 vbox->Add(my_grid);
 

}

void searchFrame::onExit(wxCommandEvent& event){
 wxMessageDialog* alert = new wxMessageDialog(this, wxT("Are you sure you want to Exit"), wxT("EXIT"), wxOK | wxCANCEL);
  if(alert->ShowModal() ==  wxOK){
    Close(true);
 }
}
