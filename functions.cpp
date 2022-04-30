#include "functions.h"

void loadData(){
  //  user user ;
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
    check_not_registered_phone_number();
    validate_phone_number();

    cout << "password must contain at least 12 characters, uppercase and lowercase letters, numbers and at least one special character\n";
    cout << "Password : ";
    info.passWord=cover_password();
    is_strong_password();
    repeat_password();

    add_new_user();
}

void changePassword(){
    string username, email;
    cout << "Please enter username: ";
    cin >> username;
    while (not existUserName(username) ){
        cout << "Please try again: ";
        cin >> username;
    }
    cout << "please enter email :";
    cin >> email;
    while (not existEmail(email)){
        cout << "please try again: ";
        cin >> email;
    }
    string newPassword , oldPassword, newPassword2;
    cout << "Please enter old password : ";
    oldPassword = cover_password();
    while(encrypt(oldPassword) != profiles[username].passWord){
        cout << "wrong password!\nPlease try again: ";
        oldPassword = cover_password();
    }
    cout << "\n\t 'password must contain at least 12 characters, uppercase and lowercase letters, numbers and at least one special character'\n\n";
    cout << "Please enter a new password:  ";
    newPassword = cover_password();

    cout << "Please enter the new password again:  ";
     newPassword2 = cover_password();
    while(newPassword != newPassword2){
        cout << "doesn't match ! \n";
        cout << "Please enter the new password again: ";
        newPassword2 = cover_password();
    }

    profiles[username].passWord = encrypt(newPassword);
    load2File();
    cout << "\n\tsuccessful process " << char(1) << endl;
    cout << "\n-------------------------------------------------------------\n";

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
        dataBase << profile.second.phoneNumber << endl;
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
    cout << "Password again : ";
    string passwordAgain=cover_password();
    while(passwordAgain != info.passWord)
    {
        cout << "ERROR : The two passwords are NOT the same.\n";
        cout << "Password again : ";
        passwordAgain = cover_password();
    }
}

void is_strong_password()
{
    bool flag=false;
    while(!flag)
    {
        if(info.passWord.size() >= 12)
        {
            int counter1=0,counter2=0,counter3=0,counter4=0;
            for(int i=0; i < info.passWord.size(); i++)
            {
                if((int)info.passWord[i] >= 48 && (int)info.passWord[i] <= 57)
                {
                    counter1++;
                }
                else if(((int)info.passWord[i] >= 33 && (int)info.passWord[i] <= 47)
                || ((int)info.passWord[i] >= 58 && (int)info.passWord[i] <= 64)
                || ((int)info.passWord[i] >= 91 && (int)info.passWord[i] <= 96)
                || ((int)info.passWord[i] >= 123 && (int)info.passWord[i] <= 126))
                {
                    counter2++;
                }
                else if((int)info.passWord[i] >= 65 && (int)info.passWord[i] <= 90)
                {
                    counter3++;
                }
                else if(((int)info.passWord[i] >= 97 && (int)info.passWord[i] <= 122))
                {
                    counter4++;
                }
            }
            if((counter1 >= 1) && (counter2 >= 1) && (counter3 >= 1) && (counter4 >= 1) )
            {
                flag = true;
                break;
            }
            else
            {
                cout << "Weak password!! password must have uppercase and lowercase letters, numbers and at least one special character.\n";
                cout << "Password : ";
                info.passWord =cover_password();
            }
        }
        else
        {
            cout << "Short password!! password must be at least 12 character\n";
            cout << "Password : ";
            info.passWord =cover_password();
        }
    }
}

string cover_password()
{
    string password = "";
    char ch_ipt;
    while (true)
    {
        ch_ipt = getch();
        if (ch_ipt == 13)
        {
            cout << endl;
            return password;
        }
        else if (ch_ipt == 8 && password.length() != 0)
        {
            password.pop_back();
            cout << "\b \b";
            continue;
        }
        else if (ch_ipt == 8 && password.length() == 0)
        {
            continue;
        }
        password.push_back(ch_ipt);
        cout << '*';
    }
}
void validate_name()
{
    regex form("[a-zA-Z\\-]+");
    while(regex_match(info.username,form)==0)
    {
        cout << "invalid username...please try again:";
        cin >> info.username;
        check_not_registered_username();
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
        check_not_registered_phone_number();
        regex_match(info.phoneNumber,form);
    }
}

void validate_email()
{
    regex form("(\\w+)@[a-zA-Z0-9]+[a-zA-Z0-9\\-]*(\\.[a-zA-Z0-9\\-]+)+[a-zA-Z0-9]+"); // /w matches any character in any case
    while(regex_match(info.email,form)==0)
    {
        cout << "invalid email!..please try again:";
        cin >> info.email;
        check_not_registered_Email();
        regex_match(info.email,form);
    }
}

void add_new_user()
{   cout << "Thanks for registration! "<<info.username<<endl;
    dataBase.open("dataBase.txt", ios :: app);
    dataBase << info.username << endl << encrypt(info.passWord) << endl << info.email << endl << info.id << endl << info.phoneNumber << endl;
    dataBase.close();
}

string username = info.username;

void check_not_registered_username()
{
    for(const auto profile : profiles)
    {
        while(profile.second.username == info.username)
        {
            cout << "used username!...please try again :";
            cin >> info.username;
            validate_name();
        }
    }
}

bool existUserName(string name){
    for (const auto profile : profiles){
        while (profile.second.username == name){
            return true;
        }
    }
    cout << "username does not exist \n";
    return false;
}

//__________________________________________________________________________________

bool existEmail(string email){
    for (const auto profile : profiles){
        while (profile.second.email == email){
            return true;
        }
    }
    cout << "This email does not exist \n";
    return false;
}

void check_not_registered_ID()
{
    for(const auto profile : profiles)
    {
        while(profile.second.id==info.id)
        {
            cout << "used ID !...please try again :";
            cin >> info.id;
        }
    }
}

void check_not_registered_Email()
{
    for(const auto profile : profiles)
    {
        while(profile.second.email==info.email)
        {
            cout << "used Email !...please try again :";
            cin >> info.email;
            validate_email();
        }
    }
}
void check_not_registered_phone_number(){
    for(const auto profile : profiles)
    {
        while(profile.second.phoneNumber==info.phoneNumber)
        {
            cout << "used phone number !...please try again :";
            cin >> info.phoneNumber;
            validate_phone_number();
        }
    }
}
void login(){
    cout << "Please enter your username: ";
    cin >> info.username;
    while (not existUserName(info.username)){
        cout << "Please try again: ";
        cin >> info.username;
    }
    cout << "Please enter your mail: ";
    cin >> info.email;
    while (profiles[info.username].email !=  info.email){
        cout << "This email does not match the username!\nPlease try again:  ";
        cin >> info.email;
    }
    cout << "Please enter your password:";
    cin >> info.passWord;
    while (profiles[info.username].passWord != encrypt(info.passWord) ){
        cout << "incorrect password!\nPlease try again: ";
        cin >> info.passWord;
    }
    cout << "Successful login, welcome  " << info.username << " " << char(1);
    cout << "\n--------------------------------------------------------------------\n";
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




