#ifndef LOGIN_APPLICATION_FUNCTIONS_H
#define LOGIN_APPLICATION_FUNCTIONS_H
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include<regex>
#include<cstring>
#include<map>
#include<vector>

using namespace std;
fstream dataBase;
struct user{
    string username="a";
    string passWord="a";
    string email="a";
    string id="a";
    string phoneNumber="a";
};
map<string,user>profiles;
user info;

void loadData();
void registration();
//void login();
void changePassword();
string  encrypt(string passWord );
void load2File();
void add_new_user();
void validate_email();
void validate_name();
void validate_phone_number();
void check_not_registered_Email();
void check_not_registered_ID();
void check_not_registered_username();
void cover_password();
void is_strong_password();
void repeat_password();

#endif //LOGIN_APPLICATION_FUNCTIONS_H



//vector <user> profiles ;

//void register1() ;
//void check_register(user & name);
//void validate_email();
//void validate_number();
//void validate_username();
//void loadData();
//bool login(user name);
//void loadData();







