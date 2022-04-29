#ifndef LOGIN_APPLICATION_FUNCTIONS_H
#define LOGIN_APPLICATION_FUNCTIONS_H
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;
struct user{
    string username;
    char passWord[8];
    string email;
};
void register2(user name) ;
bool login(user name);

#endif //LOGIN_APPLICATION_FUNCTIONS_H
