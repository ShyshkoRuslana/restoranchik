#include "System.h"
#include "Menu.h"
#include "Dish.h"
#include "Order.h"
#include <fstream>
#include <memory>
#include <stdexcept>

using namespace std;

System::System(Menu& m) : menu(m) {}
System::~System() {}

void System::start() {
    loadcustomer();
    loadorder();
    menu.loadfile();

    int choice;

    while(true) {
        cout << "\n=== SYSTEM ===" << endl;
        cout << "1. Admin login" << endl;
        cout << "2. User login" << endl;
        cout << "3. Exit" << endl;

        cin >> choice;

        switch(choice) {
            case 1:
                if(adminlogin()) {
                    adminmenu();
                }
                break;

            case 2:
                if(customerlogin() != nullptr) {
                    usermenu();
                }
                break;

            case 3:
                cout << "Bye!" << endl;
                return;

            default:
                cout << "Wrong choice!" << endl;
        }
    }
}

bool System::adminlogin() {
    string input;

    while(true) {
        cout << "Enter admin password: ";
        cin >> input;

        if(input == password) {
            cout << "Admin access granted!" << endl;
            return true;
        }
        else {
            cout << "Invalid password!" << endl;
        }
    }
}

void System::adminmenu() {
    int choice;

    while(true) {
        cout << "\n=== ADMIN MENU ===" << endl;
        cout << "1. Add dish" << endl;
        cout << "2. Update dish" << endl;
        cout << "3. Show menu" << endl;
        cout << "4. Delete dish" << endl;
        cout << "5. Create customer" << endl;
        cout << "6. Show history" << endl;
        cout << "7. Exit" << endl;

        cin >> choice;

        switch(choice) {
            case 1: {
                string name;
                double price, weight;

                cout << "Name: ";
                cin >> name;
                cout << "Price: ";
                cin >> price;
                cout << "Weight: ";
                cin >> weight;

                menu.addDish(Dish(name, price, weight));
                menu.savefile();

                savehistory("Added dish: " + name);
                break;
            }

            case 2:
                updatedish();
                break;

            case 3:
                menu.printMenu();
                break;

            case 4:
                deletedish();
                break;

            case 5:
                createcustomer();
                break;

            case 6:
                showhistory();
                break;

            case 7:
                return;

            default:
                cout << "Wrong choice!" << endl;
        }
    }
}

void System::usermenu() {
        int choice;

        while(true) {
            cout << "\n=== USER MENU ===" << endl;
            cout << "1. Show menu" << endl;
            cout << "2. Make order" << endl;
            cout << "3. Show orders" << endl;
            cout << "4. Exit" << endl;

            cin >> choice;

            switch(choice) {
                case 1:
                    menu.printMenu();
                    break;

                case 2:
                    makeorder();
                    break;

                case 3:
                    showorder();
                    break;

                case 4:
                    return;

                default:
                    cout << "Wrong choice!" << endl;
            }
        }
}

shared_ptr<Customer> System::customerlogin()  {
    string login;

    cout << "Enter login: ";
    cin >> login;

    for(auto& u : customers) {
        if(u->getlogin() == login) {
            cout << "Welcome, " << u->getname() << "!" << endl;
            return u;
        }
    }

    cout << "User not found!" << endl;
    return nullptr;
}

void System::createcustomer() {
    string name, surname, login;

    cout << "Name: ";
    cin >> name;

    cout << "Surname: ";
    cin >> surname;

    cout << "Login: ";
    cin >> login;

    for(auto& c : customers) {
        if(c->getlogin() == login) {
            cout << "Login already exists!" << endl;
            return;
        }
    }

    customers.push_back(make_shared<Customer>(name, surname, login));
    savecustomer();
    savehistory("Created customer: " + login);

    cout << "Customer created!" << endl;
}

void System::makeorder() {
    try {
        Order order(nextorderId++);
        int choice;
        menu.printMenu();
        while(true) {
            cout << "Enter dish index (-1 to finish): ";
            cin >> choice;

            if(cin.fail()) {
                throw runtime_error("Invalid input!");
            }

            if(choice == -1)
                break;

            if(choice >= 0 && choice < menu.getsize()) {
                order.addDish(menu.getdish(choice));
                cout << "Added!" << endl;
            }
            else {
                throw out_of_range("Wrong dish index!");
            }
        }

        orders.push_back(order);
        saveorder();
        savehistory("Created order ID: " + to_string(order.getId()));

        cout << "ORDER CREATED!" << endl;
        order.printInfo();
    }

    catch(exception& e) {
        cout << "Error: " << e.what() << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void System::showorder() {
    if(orders.empty()) {
        cout << "No orders yet!" << endl;
        return;
    }

    cout << "\n=== ORDER HISTORY ===" << endl;

    for(int i = 0; i < orders.size(); i++) {
        cout << "Order #" << i + 1 << endl;
        orders[i].printInfo();
    }
}

void System::updatedish() {
    menu.printMenu();

    int index;
    string name;
    double price, weight;

    cout << "Enter dish index: ";
    cin >> index;

    cout << "Enter new name: ";
    cin >> name;

    cout << "Enter new price: ";
    cin >> price;

    cout << "Enter new weight: ";
    cin >> weight;

    menu.updatedish(index, Dish(name, price, weight));
    menu.savefile();

    savehistory("Updated dish: " + name);
}

void System::deletedish() {
    menu.printMenu();

    int index;
    cout << "Enter index to delete: ";
    cin >> index;

    menu.deletedish(index);
    menu.savefile();

    savehistory("Deleted dish");
}

void System::loadcustomer() {
    customers.clear();

    ifstream file("users.txt");
    string name, surname, login;

    while(file >> name >> surname >> login) {
        customers.push_back(make_shared<Customer>(name, surname, login));
    }

    file.close();
}

void System::savecustomer() {
    ofstream file("users.txt");

    for(auto& u : customers) {
        file << u->getname() << " "
             << u->getsurname() << " "
             << u->getlogin() << endl;
    }

    file.close();
}

void System::loadorder() {
    orders.clear();

    ifstream file("orders.txt");
    int id;

    while(file >> id) {
        orders.push_back(Order(id));
    }

    file.close();
}

void System::saveorder() {
    ofstream file("orders.txt");

    for(auto& o : orders) {
        file << o.getId() << endl;
    }

    file.close();
}

void System::savehistory(string action) {
    ofstream file("history.txt", ios::app);
    file << action << endl;
}

void System::showhistory() {
    ifstream file("history.txt");
    string line;
    while(getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}
