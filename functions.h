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
user name;

//vector <user> profiles ;


void register1() ;
void check_register(user & name);
void validate_email();
void validate_number();
void validate_username();
void loadData();
bool login(user name);
void loadData();
#endif //LOGIN_APPLICATION_FUNCTIONS_H







