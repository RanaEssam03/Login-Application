#include "functions.h"

void loadData(){
    user user ;
    dataBase.open("dataBase.txt", ios:: in);

    while(! dataBase.eof()){
        string data;

        getline(dataBase, data);
          string temp = data;
        profiles[temp].username = data;

       getline(dataBase, data);
        profiles[temp].passWord = data;

        getline(dataBase, data);
        profiles[temp].email =data;

        getline(dataBase, data);
        profiles[temp].id =data ;

        getline(dataBase, data);
        profiles[temp].phoneNumber =data ;
    }
    dataBase.close();
}

void registration()
{
    cout << "Username : ";          cin >> info.username;
    check_not_registered_username();
    validate_name();

    cout << "ID : ";                cin >> info.id;
    check_not_registered_ID();

    cout << "Email : ";             cin >> info.email;
    check_not_registered_Email();
    validate_email();

    cout << "Phone number : ";      cin >> info.phoneNumber;
    validate_phone_number();

    cout << "password must contain at least 12 characters, uppercase and lowercase letters, numbers and at least one special character\n";
    cout << "Password : ";          cin >> info.passWord;
    repeat_password();
    is_strong_password();

    add_new_user();
}

void changePassword(){
    string username, email;
    cout << "Please enter username: ";
    cin >> username;
    /*function to check if the username exists or not*/
    cout << "please enter email :";
    cin >> email;
    /*function to check if the email matches the username*/
    string newPassword , oldPassword, newPassword2;
    cout << "Please enter old password : ";
    cin >> oldPassword;
    while(encrypt(oldPassword) != profiles[username].passWord){
        cout << "wrong password!\nPlease try again: ";
        cin >> oldPassword;
    }
    cout << "Please enter a new password:  ";   /////(function to check if the password valid or not) is missed
    cin >> newPassword;
    //isValidPassword
    cout << "Please enter the new password again:  ";
    cin >> newPassword2;
    while(newPassword != newPassword2){
        cout << "doesn't match ! \n";
        cout << "Please enter the new password again: ";
        cin >> newPassword2;
    }
    profiles[username].passWord = encrypt(newPassword);
    load2File();
    cout << "\n\tsuccessful process " << char(1) << endl;
}

void load2File(){
    dataBase.open("dataBase.txt", ios::trunc);
    dataBase.close();
    dataBase.open("dataBase.txt", ios :: out);
    for (const auto profile : profiles){

        dataBase << profile.second.username << endl;
        dataBase << profile.second.passWord << endl;
        dataBase << profile.second.email << endl ;
        dataBase << profile.second.id << endl;
    }
    dataBase.close();
}

string  encrypt(string passWord ){  //Caesar Cipher with fixed key = 3
    int length = passWord.size();
    string passWord1 = passWord;
    int key = 3+ 26;
    key %= 26;
    string encrypted = "";
    for (int i=0; i < length; i++){
        char c = passWord1[i];
        if (c >= 'a' && c <= 'z') {
            c += key;
            if(abs(c)> 'z'){
                c= abs(c)-26;
            }
            encrypted += c;
        }else if (c >= 'A' && c <= 'Z'){
            c += key;
            if (abs(int(c)) > 'Z') {
                c = c - 'Z' + 'A' - 1;
            }
            encrypted += c;
        }
        else {
            encrypted+= c;
        }
    }
    return encrypted;
}

void repeat_password()
{

}

void is_strong_password()
{

}

void cover_password()
{
    
}

void validate_name()
{
    regex form("{8-20}([a-zA-Z-])");
    while(regex_match(info.username,form)==0)
    {
        cout << "invalid username...please try again:";
        cin >> info.username;
        regex_match(info.username,form);
    }
}

void validate_phone_number()
{
    regex form ("01(0|1|2|5)[0-9]{8}");
    while(regex_match(info.phoneNumber,form)==0)
    {
        cout << "invalid phone number...please try again:";
        cin >> info.phoneNumber;
        regex_match(info.phoneNumber,form);
    }
}

void validate_email()
{
    regex form("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"); // /w matches any character in any case
    while(regex_match(info.email,form)==0)
    {
        cout << "invalid email!..please try again:";
        cin >> info.email;
        regex_match(info.email,form);
    }
}

void add_new_user()
{
    cout << "Thanks for registration! "<<info.username<<endl;
    dataBase.open("dataBase.txt", ios :: app);
    dataBase << info.username << endl << encrypt(info.passWord) << endl << info.email << endl << info.id << endl << info.phoneNumber << endl;
    dataBase.close();
}

string username = info.username;

void check_not_registered_username()
{
    for(int i=0;i<profiles.size();i++)
    {
        while(profiles[username].username == info.username)
        {
            cout << "used username!...please try again :";
            cin >> info.username;
            validate_name();
        }
    }
}

void check_not_registered_ID()
{
    for(int i=0;i<profiles.size();i++)
    {
        while(profiles[username].id==info.id)
        {
            cout << "used ID !...please try again :";
            cin >> info.id;
        }
    }
}

void check_not_registered_Email()
{
    for(int i=0;i<profiles.size();i++)
    {
        while(profiles[username].email==info.email)
        {
            cout << "used Email !...please try again :";
            cin >> info.email;
            validate_email();
        }
    }
}




//void register1() {
//    cout << "Please enter :";//  \n1.Username \n 2. Password \n 2.Password again  ";
//    string password ;// username, password, password2;
//    cout << "\nUserName ==> ";
//    cin >> name.username;
//    cout << "Email ==>";
//    cin >> name.email ;
//    validate_email();
//    cout << "ID ==>";
//    cin >> name.id;
//    cout << "Password ==>";
//    cin >> name.passWord;
//    cout << "Password again ==>";
//    cin>> password;
//    while(password != name.passWord){
//        cout << "passwords dont match .. please try again:";
//        cin >> password;
//    }
//
//}
//void check_register(user & name ){
//    string username = name.username;
//    for(int i=0;i<profiles.size();i++){
//     while(profiles[username].username == name.username){
//         cout << "used username!...please try again:";
//         cin>>name.username;
//     }
//     while(profiles[username].email==name.email){
//         cout << "used email!...please try again:";
//         cin >> name.email;
//     }
//     while(profiles[username].id==name.id){
//         cout << "used id!...please try again:";
//     }
//
// }
//    cout << "Thanks for registration! "<<name.username<<endl;
//    dataBase.open("dataBase.txt", ios :: app);
//    dataBase << name.username << endl << name.passWord << endl << name.email << endl<<name.id<<endl;
//    dataBase.close();
//}




//bool login(user name){
//    char c;
//    cout << "Please enter :";//  \n1.Username \n 2. Password \n 2.Password again  ";
//    string password2 ;// username, password, password2;
//    cout << "\nUserName ==> ";
//    cin >> name.username;
//    cout << "Email ==>";
//    cin >> name.email ;
//    cout << "Password ==>";
//    int i = 0 ;
//    do {
//        c = _getch();
//        if (c != 8){
//            name.passWord[i] = c;
//            cout << "*";
//            i++;
//        }
//        else name.passWord[i] = '\0';
//    } while (i !=8);
//    name.passWord[8] = '\02';
//    cin >> name.passWord;
//    ifstream dataBase;
//    dataBase.open("dataBase.txt");
//    while (! dataBase.eof()){
//        string data ;
//        getline(dataBase,data);
//        if (data == name.username +" "+ name.passWord +" "+ name.email  ){
//          return true;
//        }
//    }
//    dataBase.close();
//    return false;
//}

//string  encrypt(user & user ){  //Caesar Cipher with fixed key = 3
// int length = user.passWord.size();
// string passWord1 = user.passWord;
//    int key = 3+ 26;
//    key %= 26;
//    string encrypted = "";
//    for (int i=0; i < length; i++){
//        char c = passWord1[i];
//        if (c >= 'a' && c <= 'z') {
//            c += key;
//            if(abs(c)> 'z'){
//                c= abs(c)-26;
//            }
//            encrypted += c;
//        }else if (c >= 'A' && c <= 'Z'){
//            c += key;
//            if (abs(int(c)) > 'Z') {
//                c = c - 'Z' + 'A' - 1;
//            }
//            encrypted += c;
//        }
// }
//    return encrypted;
//
//}
//
//
//