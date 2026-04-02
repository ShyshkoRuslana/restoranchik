#include "Menu.h"
#include <iostream>

using namespace std;
void Menu::addDish(const Dish& d) {
    dishes.push_back(d);
}
void Menu::printMenu() {
    cout << "=== Menu ===" << endl;
    for (auto& d : dishes) {
        d.printInfo();
    }
}