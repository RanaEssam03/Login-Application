#include "functions.h"
#include "functions.cpp"

using namespace std;

int main()
{
    while (true)
    {
        cout << "\t\tWelcome again " << char(1) << endl;
        loadData();
        cout << "\nPlease pick one choice : ";
        cout << "\n1.Register\n2.Login\n3.Change Password\n4.Exit\n==>";
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 1)
            registration();
        else if (choice == 2)
         login();
        else if (choice == 3)
            changePassword();
        else if (choice == 4)
            break;
    }


}


//         user name ;
//         if (login(name)){
//             cout << "successful Login " << char(1) << endl ;
//         }
//         else {
//             cout << "\tFailed!"<< endl;
//         }
//     }

//    else if (choice == 3)
//        changePassword();

//     if (choice == 4)
//        break;
//    }









