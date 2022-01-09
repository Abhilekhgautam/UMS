#include "UHandle.h"
#include<time.h>

string idGenerator(){
    // Making string of year
    time_t now = time(0);
    char year[4];
    strftime(year, 100, "%y", localtime(&now));
    string stryear (year);

    // Getting user number from table
    User usr;
    int num = usr.rowNumber();
    // cout<<num<<endl;
    // cout<<num<<endl;
    int n = 1000 +num +2;
    // cout<<n<<endl;
    
    // Concatinate two string
    string id = stryear + to_string(n);
    
    // Returning id
    return id;
}

void inputData(){
    // Getting information using CLI
    string id, name, address, email, gender, phone;
    id = idGenerator();
    // cout<<id<<endl;
    cout<<"Enter Full Name: ";
    cin.ignore();
    getline(cin, name);
    cout<<"Enter Email: ";
    cin>>email;
    cout<<"Enter Address: ";
    cin.ignore();
    getline(cin, address);
    cout<<"Enter Phone No: ";
    cin>>phone;
    cout<<"Enter Gender: ";
    cin>>gender;

    // Calling to User class
    User usr;
    // Check either user is already present or not
    if (!usr.isPresent(name)){
        usr.addUser(id, name, email, address, phone, gender);
        // Success message
        cout<<"User created succesfully."<<endl;
    }

    else
        cout<<"Sorry, "<<name<<" is already in Database."<<endl;
}

bool displayAllData(){
    // Requesting for User class
    int user_found=1;
    User usr;
    int n = usr.rowNumber();
    if (n==0){
        cout<<"There is no User!!\nGo to Add user."<<endl;
        user_found=0;
    }
    else{

        RData rdata;    
        rdatas = new RData[n*sizeof(RData)];
        // cout<<n<<endl;
        rdata = usr.displayAllUser();
        cout<<"**** ALL USERS ****"<<endl;
        cout<<"*******************"<<endl;
        for(int i=0; i<n; i++){
            cout<<"--- USER "<<i+1<<" ---"<<endl;
            cout<<"*******************"<<endl;
            rdatas[i].display();
        }
        delete [] rdatas;
    }
    return user_found;
}

void displayData(){
    string name;
    cout<<"Which user do you want to search/display ?"<<endl;
    cin.ignore();
    getline(cin, name);
    
    // Calling User class object to do so
    User usr;
    RData rdata;
    if (usr.isPresent(name)){
        rdata = usr.displayUser(name);
        cout<<"*******************"<<endl;
        rdata.display();
    }
    else
        cout<<"Sorry, "<<name<< " is not Found!!"<<endl;
}

void removeData(){
    // Displaying all the users and only if users then execute

    if(displayAllData()){

        string name;
        cout<<"Which user do you want to reomve ?"<<endl;
        cin.ignore();
        getline(cin, name);

        User usr;
        RData rdata;
        // Display user info before removing from DB
        if (usr.isPresent(name)){
            cout<<"REMOVING USER..."<<endl;
            rdata = usr.displayUser(name);
            cout<<"*******************"<<endl;
            rdata.display();

            // Calling User class object to do so
            usr.removeUser(name);

            // Success message
            cout<<"Removed successfully"<<endl;
        }
        else
            cout<<name<<" is not Found!!"<<endl;
    }

}

void updateData(){
    // Displaying all the users and if found only then execute

    if(displayAllData()){

        string name, email, address, phone;
        cout<<"Which user do you want to update ?"<<endl;
        cin.ignore();
        getline(cin, name);

        User usr;
        if (usr.isPresent(name)){
            RData rdata;
            // Display user info before updatinging from DB
            cout<<"BEFORE UPDATE..."<<endl;
            rdata = usr.displayUser(name);
            cout<<"*******************"<<endl;
            rdata.display();

            // New Informations for upated user
            cout<<"Enter new information for "<<name<<endl;
            cout<<"Email: ";
            cin>>email;
            cout<<"Address: ";
            cin.ignore();
            getline(cin, address);
            cout<<"Phone: ";
            cin>>phone;

            // Sending update request to User object along with new infos
            usr.updateUser(name, email, address, phone);

            cout<<"Updated successfully"<<endl;
            // Display user info after updatinging from DB
            cout<<"\nAFTER UPDATE..."<<endl;
            rdata = usr.displayUser(name);
            cout<<"*******************"<<endl;
            rdata.display();

        }
        else
            cout<<name<<" is not Found to Update!!"<<endl;
    }
}

int main(){
    // displayAllData();
    // displayData();
    // inputData();
    // removeData();
    // updateData();
    // for(int i=0; i<5; i++)
    // string n = idGenerator();

    try{
        while(1){
        // This is CLI for user to operate and control over program 
        int choice;
            cout<<"\n1. Add user\
                \n2. Search/Display user\
                \n3. Display all users\
                \n4. Update user\
                \n5. Remove user\
                \n6. Exit\n";
            cout<<"What do You want? "<<endl;
            cin>>choice;
            switch(choice){
                case 1: inputData();
                        break;

                case 2: displayData();
                        break;

                case 3: displayAllData();
                        break;

                case 4: updateData();
                        break;

                case 5: removeData();
                        break;

                case 6: cout<<"Exiting program..."<<endl;
                        exit(1);
                
                default: throw('a');
            }
       }   
    }
    catch(char){
        cout<<"KeyError, Enter Valid Input!!"<<endl;
    }
    return 0;
}