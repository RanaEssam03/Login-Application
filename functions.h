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
};
//map<double,user>profiles;
user name;
user profile[100];
  int c=0;

vector <user> profiles ;


void register1() ;
void check_register();
void validate_email();
bool login(user name);
#endif //LOGIN_APPLICATION_FUNCTIONS_H







