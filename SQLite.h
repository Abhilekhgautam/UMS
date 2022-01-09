#include<iostream>
#include<string.h>
#include<sqlite3.h>
// #include<vector>
using namespace std;
class SQLite;
class RData;

class RData{
    char* id;
    char* name;
    char* email;
    char* address;
    char* phone;
    char* gender;

    public:

    void append(char* i, char* n, char* e, char* a, char* p, char* g){
        // cout<<"ID = "<<i<<endl;
        // cout<<"Name = "<<n<<endl;
        // cout<<"Email = "<<e<<endl;
        // cout<<"Address = "<<a<<endl;
        // cout<<"Phone = "<<p<<endl;
        // cout<<"Gender = "<<g<<endl;
        // cout<<endl;
        id = new char[strlen(i)+1];
        strcpy(id, i);

        name = new char[strlen(n)+1];
        strcpy(name, n);

        email = new char[strlen(e)+1];
        strcpy(email, e);

        address = new char[strlen(a)+1];
        strcpy(address, a);

        phone = new char[strlen(p)+1];
        strcpy(phone, p);

        gender = new char[strlen(g)+1];
        strcpy(gender, g);
    }
    void callbacks(int argc, char **argv, char **azColName){

        // Assigning returinng data into object variable
        id = new char[strlen(argv[0]) + 1];
        strcpy(id, argv[0]);

        name = new char[strlen(argv[1]) + 1];
        strcpy(name, argv[1]);

        email = new char[strlen(argv[2]) + 1];
        strcpy(email, argv[2]);

        address = new char[strlen(argv[3]) + 1];
        strcpy(address, argv[3]);

        phone = new char[strlen(argv[4]) + 1];
        strcpy(phone, argv[4]);

        gender = new char[strlen(argv[5]) + 1];
        strcpy(gender, argv[5]);

    }
    void display(){
        // cout<<"from main"<<endl;
        cout<<"ID = "<<id<<endl;
        cout<<"Name = "<<name<<endl;
        cout<<"Email = "<<email<<endl;
        cout<<"Address = "<<address<<endl;
        cout<<"Phone = "<<phone<<endl;
        cout<<"Gender = "<<gender<<endl;
        cout<<endl;
    }
};

class SQLite{
    // Pointer to SQLite connection
    sqlite3 *db;
    // Error message
    char *aErrMsg;
    // Result of the opening file
    int rOpening;
    // SQL command
    const char *sql;
    // Compile sqlite statement
    sqlite3_stmt *stmt;

    // Callback function, It contains result of sql statement
    static int callbackAll(void *fArg, int argc, char **argv, char **azColName);

    static int callback(void *fArg, int argc, char **argv, char **azColName);

    // Callback function for returning no of row
    static int numback(void *nrow, int argc, char **argv, char **azColName);

    // Callback function to return user presence in DB
    static int isPresent(void *status, int argc, char **argv, char **azColName);

    // Checking for error if any
    void checkDBError();

    public:

    // Open DB when creating an object
    SQLite();

    // Closing the connection
    void closeDB();

    // Creating DB table
    void createTable();

    // Insert data into table
    void insertData(const char* id, const char* name, const char* email, const char* address, const char* phone, const char* gender);

    // Display all the data of table
    RData displayTable();

    // Display specific data
    RData displayRow(const char* name);

    // Remove the specific user
    void removeRow(const char* name);

    // Update the specific user
    void updateRow(const char* name, const char* email, const char* address, const char* phone);

    int returnNoOfRow();

    bool searchRow(const char* name);

    // void drdata(){
    //     for(int i=0; i<10; i++)
    //         rdatas[i].display();
    // }
};

RData *rdatas;
static int count = 0;

// Return either name is in DB or not
bool SQLite::searchRow(const char* name){
    // SQL command
    char * query = NULL;

    asprintf(&query, "SELECT * FROM USERS WHERE NAME='%s';", name);
    // cout<<"query = "<<query<<endl;

    bool status = false;
    
    // Run sql
    rOpening = sqlite3_exec(db, query, isPresent, &status, &aErrMsg);
    // cout<<"rOpening = "<<rOpening<<endl;

    return status;
}

// Callback function to return user presence in DB
int SQLite::isPresent(void *status, int argc, char **argv, char **azColName){
    bool *found = (bool*)status;
    if(argc != 0)
        *found = true;
    return 0;
}

// Return total no of row present
int SQLite::numback(void *nrow, int argc, char **argv, char **azColName){
    int *num = (int*)nrow;
    *num = atoi(argv[0]);
    // cout<<*num<<endl;
    return 0;
}

// To return the number of row of table
int SQLite::returnNoOfRow(){
    // SQL for display all
    sql = "SELECT COUNT(*) FROM USERS;" ;
    // cout<<"sql = "<<sql<<endl;

    int nrow=0;

    // Run sql
    rOpening = sqlite3_exec(db, sql, numback, &nrow, &aErrMsg);
    // cout<<"rOpening = "<<rOpening<<endl;
    // cout<<nrow<<endl;

    return nrow;
}

// Update a row by its name
void SQLite::updateRow(const char* name, const char* email, const char* address, const char* phone){
    // SQL command
    char * query = NULL;

    asprintf(&query, "UPDATE USERS SET EMAIL='%s', ADDRESS='%s', PHONE='%s' WHERE NAME='%s';", email, address, phone, name);

    // cout<<"Query = "<<query<<endl;

    // Prepere the query
    sqlite3_prepare(db, query, strlen(query), &stmt, NULL);
    // cout<<"SQL statement = "<<stmt<<endl;

    // Testing the statement
    rOpening = sqlite3_step(stmt);
    // cout<<"After testing rOpening = "<<rOpening<<endl;

    // Final the statement
    sqlite3_finalize(stmt);

    // Free the space of query
    free(query);
    // cout<<"Query after free: "<<query<<endl;
}

// Remove a row by name
void SQLite::removeRow(const char* name){
    // SQL command
    char * query = NULL;

    asprintf(&query, "DELETE FROM USERS WHERE NAME='%s';", name);
    // cout<<"query = "<<query<<endl;

    // Run sql
    rOpening = sqlite3_exec(db, query, callback, 0, &aErrMsg);
    // cout<<"rOpening = "<<rOpening<<endl;
}

// Display a row by name
RData SQLite::displayRow(const char* name){
    // SQL command
    char * query = NULL;

    asprintf(&query, "SELECT * FROM USERS WHERE NAME='%s';", name);
    // cout<<"query = "<<query<<endl;

    RData rdata;
    
    // Run sql
    rOpening = sqlite3_exec(db, query, callback, &rdata, &aErrMsg);
    // cout<<"rOpening = "<<rOpening<<endl;

    return rdata;
}

// To display all the data of table
RData SQLite::displayTable(){
    // SQL for display all
    sql = "SELECT * FROM USERS;" ;
    // cout<<"sql = "<<sql<<endl;

    RData rdata;
    // rdata = (RData*) malloc(9*sizeof(RData));

    // Run sql
    rOpening = sqlite3_exec(db, sql, callbackAll, &rdata, &aErrMsg);
    // cout<<"rOpening = "<<rOpening<<endl;

    // drdata();

    return rdata;
}

// Insert al the data into table
void SQLite::insertData(const char* id, const char* name, const char* email, const char* address, const char* phone, const char* gender){
    // SQL query
    char * query = NULL;

    // Making single string of command and asign into query
    asprintf(&query, "INSERT INTO USERS(ID, NAME, EMAIL, ADDRESS, PHONE, GENDER) VALUES ('%s', '%s', '%s', '%s', '%s', '%s');", id, name, email, address, phone, gender);
    // cout<<"query = "<<query<<endl;

    // Prepere the query
    sqlite3_prepare(db, query, strlen(query), &stmt, NULL);
    // cout<<"SQL statement = "<<stmt<<endl;

    //  rOpening = sqlite3_exec(db, query, callback, 0, &aErrMsg);

    // Testing the statement
    rOpening = sqlite3_step(stmt);
    // cout<<"After testing rOpening = "<<rOpening<<endl;

    // Final the statement
    sqlite3_finalize(stmt);

    // Free the space of query
    free(query);
    // cout<<"Query after free: "<<query<<endl;
}

// Creating DB table
void SQLite::createTable(){
    // SQL command to create table
    sql = "CREATE TABLE IF NOT EXISTS USERS("
            "ID INT PRIMARY KEY NOT NULL UNIQUE, "
            "NAME TEXT NOT NULL UNIQUE, "
            "EMAIL TEXT NOT NULL UNIQUE, "
            "ADDRESS TEXT NOT NULL, "
            "PHONE CHAR(15) NOT NULL UNIQUE, "
            "GENDER CHAR(7) NOT NULL);";
    // cout<<"SQL = "<<sql<<endl;
    // Run the sql
    rOpening = sqlite3_exec(db, sql, callback, 0, &aErrMsg);
    // cout<<"After running command rOpening = "<<rOpening<<endl;
}

// Open connection
SQLite::SQLite(){
    // Store the result of opening file
    rOpening = sqlite3_open("User.db", &db);
    // cout<<"rOpening = "<<rOpening<<endl;
    // Check errors
    // cout<<"DB opened succesfully"<<endl;
    checkDBError();
}

// Closing the connection
void SQLite::closeDB(){
        sqlite3_close(db);
        // cout<<"DB closed succesfully"<<endl;
    }

// Callback function, It contains result of sql statement
int SQLite::callback(void *fArg, int argc, char **argv, char **azColName){
    // void *fArg: It is the fourth argument pass in sqlite3_exec() command
    // int argc: It holds the number of results ie. number of rows(may be in some case)
    // char **argv (array of array of charactor): Holds each values of each column
    // char **azColName (array of pointer to pointer of charactor array): Holds each column returned

    // Now to display the returned contents, It goes row by row
    // cout<<"--- User ---"<<endl;
    // for(int i=0; i<argc; i++){
    //     cout<<azColName[i]<< "--> "<<argv[i]<<endl;
    // }
    //  // Inserting new line after completion of first row
    // cout<<endl;

    RData *rd = (RData *) fArg;
    rd->callbacks(argc, argv, azColName);

    // Returning success
    return 0;
}
int SQLite::callbackAll(void *fArg, int argc, char **argv, char **azColName){
    // void *fArg: It is the fourth argument pass in sqlite3_exec() command
    // int argc: It holds the number of results ie. number of rows(may be in some case)
    // char **argv (array of array of charactor): Holds each values of each column
    // char **azColName (array of pointer to pointer of charactor array): Holds each column returned

    // Now to display the returned contents, It goes row by row

    RData *rd = (RData *) fArg;
    
    // Assigning returinng data into object variable
        char* id = new char[strlen(argv[0]) + 1];
        strcpy(id, argv[0]);

        char* name = new char[strlen(argv[1]) + 1];
        strcpy(name, argv[1]);

        char* email = new char[strlen(argv[2]) + 1];
        strcpy(email, argv[2]);

        char* address = new char[strlen(argv[3]) + 1];
        strcpy(address, argv[3]);

        char* phone = new char[strlen(argv[4]) + 1];
        strcpy(phone, argv[4]);

        char* gender = new char[strlen(argv[5]) + 1];
        strcpy(gender, argv[5]);

        rdatas[count].append(id, name, email, address, phone, gender);
        rd->append(id, name, email, address, phone, gender);

        delete [] id;
        delete [] name;
        delete [] email;
        delete [] address;
        delete [] phone;
        delete [] gender;

    ++count;
    // cout<<count<<endl;

    // Returning success
    return 0;
}

void SQLite::checkDBError(){
    if(rOpening){
        // Generally rOpening is zero if not error, If error found display error
        cout<<"DB Error: "<<sqlite3_errmsg(db)<<endl;
        // closing the database
        closeDB();
    }
}