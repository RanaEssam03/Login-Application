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
#include <tchar.h>
#include <Windows.h>
#include<time.h>
#include "EASendMailObj.tlh"
using namespace EASendMailObjLib;

using namespace std;

//_____________________________________________________________
void loadData();
void registration();
int login();
void changePassword();
string encrypt(string passWord );
void load2File();
void add_new_user();
void validate_email();
void validate_name();
void validate_phone_number();
void check_not_registered_Email();
void check_not_registered_ID();
void check_not_registered_username();
void check_not_registered_phone_number();
string cover_password();
void is_strong_password();
void repeat_password();
bool existUserName(string name);
bool existEmail(string email);
int sendEmail();
int forgetPassword();

#endif //LOGIN_APPLICATION_FUNCTIONS_H








