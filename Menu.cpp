#include "Menu.h"
#include <iostream>
#include <fstream>
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
void Menu::updatedish(int index, const Dish &d) {
    if(index >= 0 && index < dishes.size()) {
        dishes[index] = d;
    }
    else {
        cout << "Invalid index!\n";
    }
}
void Menu::deletedish(int index) {
    if(index >= 0 && index < dishes.size()) {
        dishes.erase(dishes.begin() + index);
    }
    else {
        cout << "Invalid index!\n";
    }
}
int Menu::getsize() {
    return dishes.size();
}

Dish Menu::getdish(int index) {
    return dishes[index];
}
void Menu::savefile()  {
    ofstream file("menu.txt");

    for(const Dish& d : dishes) {
        file << d.getname() << " " << d.getprice() << " " << d.getweight() << endl;
    }

    file.close();
}
void Menu::loadfile(){
    ifstream file("menu.txt");

    if(!file.is_open()) return;

    string name;
    double price, weight;

    while(file >> name >> price >> weight) {
        Dish d(name, price, weight);
        dishes.push_back(d);
    }


    file.close();
}