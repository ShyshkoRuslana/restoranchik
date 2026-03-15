#include <iostream>
#include <utility>
#include "Dish.h"
#include <string>
using namespace std;
Dish::Dish() : Dish("Unknown", 0.0, 0.0) {}
Dish::Dish(string name)
        : name(name), price(0.0), weight(0.0) {}
Dish::Dish(string name, double price) {
    name = name;
    price = price;
    weight=0.0;
}
Dish::Dish(string name, double price, double weight)
        : name(name), price(price), weight(weight) {}

Dish::~Dish(){}

void Dish::printInfo(){
    cout << "Dish: " << name <<  " | Price: " << price << " | Weight: " << weight << endl;
}