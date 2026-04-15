#include "System.h"
#include "Menu.h"
#include "Dish.h"
#include "Order.h"

using namespace std;
System::System(Menu& m) : menu(m) {}
System::~System() {}
void System::start() {
    int choice;
    while(true){
        cout << "=== System ===" << endl;
        cout << "1. Admin login" << endl;
        cout << "2. Admin menu" << endl;
        cout << "3. User menu" << endl;
        cout << "4. Exit" << endl;
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
                usermenu();
                break;
            case 4:
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
        cout << "2. Update dish" << endl;
        cout << "3. Show menu" << endl;
        cout << "4. Delete dish" << endl;
        cout << "5. Exit" << endl;
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
                updatedish();
                break;
            case 3:
                cout << "Show menu..." << endl;
                menu.printMenu();
                break;
            case 4:
                deletedish();
                break;
            case 5:
                return;
            default:
                cout << "Wrong choice!" << endl;
        }
    }
}
void System::usermenu()  {
    int choice;
    while(true){
        cout << "=== User Menu ===" << endl;
        cout << "1. Show menu" << endl;
        cout << "2. Make order" << endl;
        cout << "3. Show my order" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Show menu" << endl;
                menu.printMenu();
                break;
            case 2:
                makeorder();
                break;
            case 3:
                for(auto& o : orders) {
                    o.printInfo();
                }
            case 4:
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
void System::updatedish() {
    menu.printMenu();
    int index;
    cout << "Enter index: " << endl;
    cin >> index;
    string name;
    double price, weight;
    cout << "Enter dish (name,price,weight): " << endl;
    cin >> name >> price >> weight;
    menu.updatedish(index, Dish(name,price,weight));
}
void System::deletedish() {
    menu.printMenu();
    int index;
    cout << "Enter index: " << endl;
    cin >> index;
    menu.deletedish(index);

}

void System::makeorder(){
        Order order(nextorderId++);
        int choice;
        while(true) {
            menu.printMenu();
            cout << "Enter dish index (-1 to finish): " << endl;
            cin >> choice;
            if(choice == -1) break;
            if(choice >= 0 && choice < menu.getsize()) {
                order.addDish(menu.getdish(choice));
                cout << "Added!" << endl;
            }
            else {
                cout << "Wrong index!" << endl;
            }
        }
        orders.push_back(order);
        cout << "ORDER CREATED!" << endl;
        order.printInfo();
    }
void System::showorder() {
    if(orders.empty()) {
        cout << "No orders yet!" <<endl ;
        return;
    }
    cout << "=== ORDER HISTORY ===" << endl;
    for(int i = 0; i < orders.size(); i++) {
        cout << "Order #" << (i + 1) << endl;
        orders[i].printInfo();
    }
}


