#include "Menu.h"
#include <iostream>

void Menu::addDish(const Dish& d) {
    dishes.push_back(d);
}
void Menu::printMenu() {
    std::cout << "=== Dishes ===" << std::endl;
    for (auto& d : dishes) {
        d.printInfo();
    }
}