#include "functions.h"

void register1() {
    cout << "Please enter :";//  \n1.Username \n 2. Password \n 2.Password again  ";
    string password ;// username, password, password2;
    cout << "\nUserName ==> ";
    cin >> name.username;
    cout << "Email ==>";
    cin >> name.email ;
    cout << "Password ==>";
    cin >> name.passWord;
    cout << "Password again ==>";
    cin>> password;
    while(password != name.passWord){
        cout << "passwords dont match .. please try again:";
        cin >> password;
    }

}
void check_register(){
    vector<string>file;
    string data;
    dataBase.open("dataBase.txt",ios::in);
    while(!dataBase.eof()){
        dataBase.getline(dataBase);
        while(data == name.username){
        cout << "The username,email or id are used before....please try again:";
        cout << "Please enter :";//  \n1.Username \n 2. Password \n 2.Password again  ";
        string password ;// username, password, password2;
        cout << "\nUserName ==> ";
        cin >> name.username;
        cout << "Email ==>";
        cin >> name.email ;
        cout << "Password ==>";
        cin >> name.passWord;
        cout << "Password again ==>";
        cin>> password;
        while(password != name.passWord){
            cout << "passwords dosent match..please try again:";
            cin >> password;
        }
    }}

    dataBase.close();
    cout << "Thanks for registration! "<<name.username<<endl;
    dataBase.open("dataBase.txt", ios :: app);
    dataBase << name.username << endl << name.passWord << endl << name.email << endl<<name.id;
    dataBase.close();}




bool login(user name){
    char c;
    cout << "Please enter :";//  \n1.Username \n 2. Password \n 2.Password again  ";
    string password2 ;// username, password, password2;
    cout << "\nUserName ==> ";
    cin >> name.username;
    cout << "Email ==>";
    cin >> name.email ;
    cout << "Password ==>";
//    for (int i = 0 ; i < 8 ; i++){
//        c = getch();
//        cout <<"*";
//        name.passWord[i] = c;
//    }
    int i = 0 ;
    do {
        c = _getch();
        if (c != 8){
            name.passWord[i] = c;
            cout << "*";
            i++;
        }
        else name.passWord[i] = '\0';
    } while (i !=8);
//    name.passWord[8] = '\02';
    //cin >> name.passWord;
    ifstream dataBase;
    dataBase.open("dataBase.txt");
    while (! dataBase.eof()){
        string data ;
        getline(dataBase,data);
        if (data == name.username +" "+ name.passWord +" "+ name.email  ){
          return true;
        }
    }
    dataBase.close();
    return false;
}




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






//
