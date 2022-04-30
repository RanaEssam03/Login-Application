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

//            user.username = ;
//            user.email =profiles[temp].email ;
//            user.passWord = profiles[temp].passWord;
//            user.phoneNumber =

    }
    dataBase.close();

}

void register1() {
    cout << "Please enter :";//
    string password, password2 ;
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
    cin >> password;
    cout << "Password again ==>";
    cin>> password2;
    while(password2 != password){
        cout << "passwords dont match .. please try again:";
        cin >> password2;
    }
    name.passWord = encrypt(password);

}
void check_register(user & name ){
    string username = name.username;

        for (const auto profile : profiles) {

            while (profile.second.username == name.username) {
                cout << "used username!...please try again:";
                cin >> name.username;
                 validate_username();
            }
            while (profile.second.email == name.email) {
                cout << "used email!...please try again:";
                cin >> name.email;
                validate_email();
            }
            while (profile.second.id == name.id) {
                cout << "used id!...please try again:";
                cin >> name.id;
            }
            while (profile.second.phoneNumber == name.phoneNumber) {
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
////    name.passWord[8] = '\02';
//    //cin >> name.passWord;
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
 }
    return encrypted;
}

void changePassword(){
    string username, email;
    cout << "Please enter username: ";
    cin >> username;
    cout << "please enter email :";
    cin >> email;
    string newPassword , oldPassword, newPassword2;
    cout << "Please enter old password : ";
    cin >> oldPassword;
    while(encrypt(oldPassword) != profiles[username].passWord){
        cout << "wrong password!\nPlease try again: ";
        cin >> oldPassword;
    }
    cout << "Please enter a new password:  ";   /////(function to check of the password valid or not) is missed
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



