#include "functions.cpp"
using namespace std;

int main(){
    cout << "\t\tWelcome again " << char(1) << endl;
    while (true){
    cout << "Please pick one choice : ";
    cout << "\n1.Register\n2.Login\n3.Change Password\n4.Exit\n==>";
    int choice;
    cin >> choice;
    cin.ignore();
    if (choice == 1){
        user name ;
        register2( name );
    }
     if (choice == 2){
         user name ;
         if (login(name)){
             cout << "successful Login " << char(1) << endl ;
         }
         else {
             cout << "\tFailed!"<< endl;
         }
     }

//    else if (choice == 3)
//        changePassword();

     if (choice == 4)
        break;
    }
}








