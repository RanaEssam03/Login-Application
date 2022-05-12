#include "functions.h"

//int code = 0;
bool flagflag = false;
struct user {
    string username = "a";
    string passWord = "a";
    string email = "a";
    string id = "a";
    string phoneNumber = "a";
};
map<string, user>profiles;
user info;
fstream dataBase;

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

        getline(dataBase, data);
        profiles[temp].phoneNumber =data ;
    }
    dataBase.close();
}
//___________________________________________________________
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
//___________________________________________________________
void changePassword(){
    string username, email;
    cout << "Please enter username: ";
    cin >> username;
    while (! existUserName(username) ){
        cout << "Please try again : ";
        cin >> username;
    }
    cout << "please enter email :";
    cin >> email;
    while (! existEmail(email)){
        cout << "please try again : ";
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
    info.passWord = cover_password();
    is_strong_password();
    repeat_password();
    profiles[username].passWord = encrypt(info.passWord);
    load2File();
    cout << "\n\tsuccessful process " << char(1) << endl;
}
//___________________________________________________________
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
//___________________________________________________________
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
//___________________________________________________________
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
//___________________________________________________________
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
//___________________________________________________________
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
//___________________________________________________________
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
//___________________________________________________________
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
//___________________________________________________________
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
//___________________________________________________________
void add_new_user()
{   cout << "Thanks for registration! "<<info.username<<endl;
    dataBase.open("dataBase.txt", ios :: app);
    dataBase << info.username << endl << encrypt(info.passWord) << endl << info.email << endl << info.id << endl << info.phoneNumber << endl;
    dataBase.close();
}
//___________________________________________________________
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
//___________________________________________________________
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
//___________________________________________________________
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
//___________________________________________________________
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
//___________________________________________________________
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
//___________________________________________________________
int login() {
    int trials = 0;
    while (true) {
        if (trials != 3) {
            trials++;
            cout << "\nPlease enter your \n";
            cout << "Username : ";
            cin >> info.username;
            while (!existUserName(info.username)) {
                cout << "Please try again : ";
                cin >> info.username;
            }
            cout << "Email : ";
            cin >> info.email;
            while (profiles[info.username].email != info.email) {
                cout << "This email does not match the username!\nPlease try again :  ";
                cin >> info.email;
            }
            cout << "If you don't remember your password -> enter f\nif not -> enter c to continue\n---> ";
            char s;
            cin.ignore();
            cin >> s;
            if (s == 'f')
            {
                forgetPassword();
                if (flagflag == true)
                {
                    return 0;
                }
                else
                {
                    cout << "Successful login, welcome  " << info.username << " " << char(1);
                    return 0;
                }
            }
            else {
                cout << "Password :";
                info.passWord = cover_password();
                if (profiles[info.username].passWord != encrypt(info.passWord)) {
                    cout << "Wrong password........Failed login!\n-------------";
                }
                else {
                    cout << "Successful login, welcome  " << info.username << " " << char(1);
                    break;
                    return 0;
                }
            }
        }
        else
        {
            cout << "\nYour access to the system is denied !\n";
            break;
            return 0;
        }
    }
}

const int ConnectNormal = 0;
const int ConnectSSLAuto = 1;
const int ConnectSTARTTLS = 2;
const int ConnectDirectSSL = 3;
const int ConnectTryTLS = 4;

int sendEmail()
{
    ::CoInitialize(NULL);

    IMailPtr oSmtp = NULL;
    oSmtp.CreateInstance(__uuidof(EASendMailObjLib::Mail));
    oSmtp->LicenseCode = _T("TryIt");

    // Set your sender email address
    oSmtp->FromAddr = _T("AsmaaIHeikal@gmail.com");
    // Add recipient email address
    char a[30];
    int c=0;
    for(char i:info.email)
    {
        a[c]=i;
        c++;
    }
    a[info.email.size()] = '\0';
    oSmtp->AddRecipientEx(a, 0);

    // Set email subject
    oSmtp->Subject = _T("Your verification code");
    // Set email body
    /* srand(time(0));
    code = (rand() % 1000);
    string x = to_string(code);
    char b[20];
    int d = 0;
    for (char i : x)
    {
        b[d] = i;
        d++;
    }
    b[info.email.size()] = '\0';*/
    oSmtp->BodyText = _T("285571");

    // Your SMTP server address
    oSmtp->ServerAddr = _T("smtp.gmail.com");

    // User and password for ESMTP authentication, if your server doesn't
    // require User authentication, please remove the following codes.
    oSmtp->UserName = _T("AsmaaIHeikal@gmail.com");
    oSmtp->Password = _T("wuukyzbewwrgbyxz");

    // Most mordern SMTP servers require SSL/TLS connection now.
    // ConnectTryTLS means if server supports SSL/TLS, SSL/TLS will be used automatically.
    oSmtp->ConnectType = ConnectTryTLS;

    // If your SMTP server uses 587 port
    oSmtp->ServerPort = 587;

    // If your SMTP server requires SSL/TLS connection on 25/587/465 port
    // oSmtp->ServerPort = 25; // 25 or 587 or 465
    // oSmtp->ConnectType = ConnectSSLAuto;

    _tprintf(_T("Start to send email ...\r\n"));

    if (oSmtp->SendMail() == 0)
    {
        _tprintf(_T("email was sent successfully!\r\n"));
    }
    else
    {
        _tprintf(_T("failed to send email with the following error: %s\r\n"),
                 (const TCHAR*)oSmtp->GetLastErrDescription());
    }

    return 0;
}

int forgetPassword()
{
    cout << "You will recieve a verification code on your email" << endl;
    sendEmail();
    cout << "Enter the code : ";
    long long int s;
    cin.ignore();
    cin >> s;
    if (s == 285571)
    {
        cout << "Enter your data again to change password" << endl;
        changePassword();
    }
    else {
        cout << "Try again later";
        flagflag = true;
        return 0;
    }
}



