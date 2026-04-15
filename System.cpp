#include "System.h"
using namespace std;
System::~System() {}
void System::start() {
    int choice;
    while(true){
        cout << "=== System ===" << endl;
        cout << "1. Admin login" << endl;
        cout << "2. User name" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Admin selected" << endl;
                break;
            case 2:
                cout << "User selected" << endl;
                break;
            case 3:
                cout << "Bye" << endl;
                break;
            default:
                cout << "Wrong choice!" << endl;
        }

    }


}