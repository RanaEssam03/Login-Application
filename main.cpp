#include "functions.h"

int main()
{
    while (true)
    {
        cout << "\n--------------------------------------------------------------------\n";
        cout << "\t\tWelcome again " << char(1) << endl;
        cout << "\nPlease pick one choice : ";
        cout << "\n1.Register\n2.Login\n3.Change Password\n4.Exit\n==>";
        loadData();
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
        else
            cout << "Invalid option!";
    }
    
}










