#include "SQLite.h"
#include<time.h>
class User;

class User{
    // User Informations
    string id;
    string name;
    string email;
    string address;
    string phone;
    string gender;
    string old_name;

    public:
    // Set default constructor
    User(){}

    // Make a constructor to accept parameters
    User(string name, string email, string address, string phone, string gender);

    bool addUser();

    RData* displayAllUser();

    RData displayUser(string name);

    bool removeUser(string name);

    bool updateUser(string old_name);

    int rowNumber();

    bool isPresent(string name);

};

// Make a constructor to accept parameters
// Data from front-end comes here
User::User(string name, string email, string address, string phone, string gender){
    // Assigining values to object
    this->name = name;
    this->email = email;
    this->address = address;
    this->phone = phone;
    this->gender = gender;
    // std::cout<<name;
    // Also generate id here
    // Making string of year
    time_t now = time(0);
    char year[4];
    strftime(year, 100, "%y", localtime(&now));
    string stryear (year);

    // Getting user number from table
    User usr;
    int num = usr.rowNumber();
    // cout<<num<<endl;
    int n = 1000 +num +2;
    // cout<<n<<endl;
    
    // Concatinate two string
    this->id = stryear + to_string(n);
        // cout<<"ID = "<<id<<endl;
        // cout<<"Name = "<<name<<endl;
        // cout<<"Email = "<<email<<endl;
        // cout<<"Address = "<<address<<endl;
        // cout<<"Phone = "<<phone<<endl;
        // cout<<"Gender = "<<gender<<endl;
        // cout<<endl;

}

// Returning presence status
bool User::isPresent(string name){
    this->name = name;
    bool present = false;
    SQLite sqldb;
    present = sqldb.searchRow(name.c_str());
    return present;
}

// Returning the number of row
int User::rowNumber(){
    SQLite sqldb;
    int rno = sqldb.returnNoOfRow();
    sqldb.closeDB();
    return rno;
}

// Updating user 
bool User::updateUser(string old_name){
    // Asssigning values
    this->old_name = old_name;
    bool success;

    // Open, send request and close DB
    // Update name with new infos in db
    SQLite sqldb;
    success = sqldb.updateRow(old_name.c_str(), name.c_str(), email.c_str(), address.c_str(), phone.c_str(), gender.c_str());
    sqldb.closeDB();
    return success;
}

// Remove user by its name
bool User::removeUser(string name){
    this->name = name;
    bool success;

    // Opening, requesting and closing DB
    SQLite sqldb;
    success = sqldb.removeRow(name.c_str());
    sqldb.closeDB();
    return success;
}

// Display user by its name
RData User::displayUser(string name){
    this->name = name;
    // Opening, requesting and closing DB
    SQLite sqldb;
    RData rdata;
    rdata = sqldb.displayRow(name.c_str());
    sqldb.closeDB();
    return rdata;
}

// Display all the users from DB
RData* User::displayAllUser(){
    // Opening, requesting and closing DB
    int row_num = rowNumber();
    SQLite sqldb;
    // Declearing object to return data
    rdatas = new RData[row_num * sizeof(RData)];
    RData rdta;
    rdta = sqldb.displayTable();
    // cout<<sqldb.returnNoOfRow()<<endl;
    // cout<<"in uhandle"<<endl;
    // (rdta )->display();
    sqldb.closeDB();
    return rdatas;
}

// Adding user into DB
// Also return success message back 
bool User::addUser(){
    bool success=false;
    // Opening DB and passing infos
    SQLite sqldb;
    if(sqldb.createTable()){

        success = sqldb.insertData(id.c_str(), name.c_str(), email.c_str(), address.c_str(), phone.c_str(), gender.c_str());
    }
    sqldb.closeDB();
    return success;
}