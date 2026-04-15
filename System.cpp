#include "System.h"
#include "Menu.h"
#include "Dish.h"
using namespace std;
System::System(Menu& m) : menu(m) {}
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
                if(adminlogin()){
                    adminmenu();}
                break;
            case 2:
                adminmenu();
                break;
            case 3:
                cout << "User selected" << endl;
                username();
                break;
            case 4:
                break;
            case 5:
                cout << "Bye" << endl;
                break;
            default:
                cout << "Wrong choice!" << endl;
        }
    }
}
void System::adminmenu() {
    int choice;
    while (true){
        cout << "=== Admin Menu ===" << endl;
        cout << "1. Add dish" << endl;
        cout << "2. Show menu" << endl;
        cout << "3. Delete dish" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:{
                cout << "Add dish..." << endl;
                string name;
                double price, weight;
                cout << "Enter dish (name,price,weight): " << endl;
                cin >> name >> price >> weight;
                Dish d (name,price,weight);
                menu.addDish(d);
                break;
            }
            case 2:
                cout << "Show menu..." << endl;
                menu.printMenu();
                break;
            case 3:
                cout << "User menu" << endl;
                break;
            case 4:
                return;
            default:
                cout << "Wrong choice!" << endl;
        }
    }
}
void System::username()  {
    int choice;
    while(true){
        cout << "=== User Menu ===" << endl;
        cout << "1. Show menu" << endl;
        cout << "2. Make order" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Show menu" << endl;
                menu.printMenu();
                break;
            case 2:
                cout << "User menu" << endl;
                break;
            case 3:
                return;
            default:
                cout << "Wrong choice!" << endl;
        }
    }
}
void System::printMenu() {
    cout << "=== Menu ===" << endl;
    for (auto& d : dishes) {
        d.printInfo();
    }
}
void System::addDish(const Dish& d) {
    dishes.push_back(d);
}
bool System::adminlogin() {
    string input;
    while(true){
        cout << "Enter password: " << endl;
        cin >> input;
        if (input == password){
            cout << "Super " << endl;
            return true;
        }
        else{
            cout << "invalid " << endl;
        }
    }
}
void System::usermenu() {}