#include "System.h"
using namespace std;
System::~System() {}
void System::start() {
    int choice;
    while(true){
        cout << "=== System ===" << endl;
        cout << "1. Admin login" << endl;
        cout << "2. Admin menu" << endl;
        cout << "3. User name" << endl;
        cout << "4. User menu" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Admin selected" << endl;
                adminlogin();
                break;
            case 2:
                cout << "Admin menu" << endl;
                adminmenu();
                break;
            case 3:
                cout << "User selected" << endl;
                username();
                break;
            case 4:
                cout << "User menu" << endl;
                usermenu();
                break;
            case 5:
                cout << "Bye" << endl;
                break;
            default:
                cout << "Wrong choice!" << endl;
        }
    }
}
void System::adminlogin() {}
void System::adminmenu() {}
void System::username() {}
void System::usermenu() {}