#include "functions.h"


void loadData(){
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


    }
    dataBase.close();

}

void register1() {
    cout << "Please enter :";//  \n1.Username \n 2. Password \n 2.Password again  ";
    string password ;// username, password, password2;
    cout << "\nUserName ==> ";
    cin >> name.username;
    validate_username();
    cout << "Email ==>";
    cin >> name.email ;
    validate_email();
    cout << "Phone number ==>";
    cin>>name.phoneNumber;
    validate_number();
    cout << "ID ==>";
    cin >> name.id;
    cout << "Password ==>";
    cin >> name.passWord;
    cout << "Password again ==>";
    cin>> password;
    while(password != name.passWord){
        cout << "passwords dont match .. please try again:";
        cin >> password;
    }

}
void check_register(user & name ){
    string username = name.username;
    for(int i=0;i<profiles.size();i++){
     while(profiles[username].username == name.username){
         cout << "used username!...please try again:";
         cin>>name.username;
         validate_username();
     }
     while(profiles[username].email==name.email){
         cout << "used email!...please try again:";
         cin >> name.email;
         validate_email();
     }
     while(profiles[username].id==name.id){
         cout << "used id!...please try again:";
         cin >> name.id;
     }
     while(profiles[username].phoneNumber == name.phoneNumber){
         cout << "used phone number...please try again:";
         cin >> name.phoneNumber;
         validate_number();
     }

 }
    cout << "Thanks for registration! "<<name.username<<endl;
    dataBase.open("dataBase.txt", ios :: app);
    dataBase << name.username << endl << name.passWord << endl << name.email << endl<<name.id<<endl;
    dataBase.close();
}




bool login(user name){
    char c;
    cout << "Please enter :";//  \n1.Username \n 2. Password \n 2.Password again  ";
    string password2 ;// username, password, password2;
    cout << "\nUserName ==> ";
    cin >> name.username;
    cout << "Email ==>";
    cin >> name.email ;
    cout << "Password ==>";
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
void validate_email(){
    regex form("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"); // /w matches any character in any case
    while(regex_match(name.email,form)==0){
     cout << "invalid email!..please try again:";
     cin >> name.email;
     regex_match(name.email,form);
    }
}
void validate_number(){
    regex form ("01(0|1|2|5)[0-9]{8}");
    while(regex_match(name.phoneNumber,form)==0){
        cout << "invalid phone number...please try again:";
        cin >> name.phoneNumber;
        regex_match(name.phoneNumber,form);
    }
}
void validate_username(){
    regex form("{8-20}((\\-)*[a-zA-Z]+(\\-)*[a-zA-z]*(\\-)*");
    while(regex_match(name.username,form)==0){
        cout << "invalid username...please try again:";
        cin >> name.username;
        regex_match(name.username,form);
    }

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
