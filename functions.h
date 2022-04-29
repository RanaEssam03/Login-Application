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
    string username;
    string passWord;
    string email;
    string id;
};
map<double,user>profiles;
user name;



void register1() ;
void check_register();
bool login(user name);
#endif //LOGIN_APPLICATION_FUNCTIONS_H







