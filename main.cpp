#include <iostream>
using namespace std;
int main(){
    cout << "\t\tWelcome to the Application " << char(1) << endl;
    while (true){
    cout << "Please pick one choice : ";
    cout << "\n1.Register\n2.Login\n3.Change Password\n4.Exit";
    int choice;

    cin >> choice;
//    if (choice == 1)
//        register();
//    else if (choice == 2)
//        login();
//    else if (choice == 3)
//        changePassword();
    if (choice == 4)
        break;
    }

}


