#include "Dish.h"
#include <iostream>
#include <string>
using namespace std;

Dish::Dish() : Dish("Unknown", 0.0, 0.0) {}
Dish::Dish(string name) : name(name), price(0.0), weight(0.0) {}
Dish::Dish(string name, double price) {
    this->name = name;
    this->price = price;
    this->weight = 0.0;}
Dish::Dish(string name, double price, double weight): name(name), price(price), weight(weight) {}

Dish::Dish(const Dish& other) {
    name=other.name;
    price=other.price;
    weight=other.weight;}

Dish::Dish(Dish&& other) {
    name= std::move(other.name);
    price = other.price;
    weight = other.weight;}

Dish::~Dish() {}

Dish Dish::operator+(const Dish& other) {
    return Dish(name + " and " + other.name, price + other.price, weight + other.weight);
}

Dish Dish::operator++() {
    price++;
    return *this;
}

ostream& operator<<(ostream& out, const Dish& d) {
    out << d.name << " | Price: " << d.price << " | Weight: " << d.weight;
    return out;
}
istream& operator>>(istream& in, Dish& d) {
    in >> d.name >> d.price >> d.weight;
    return in;
}

void Dish::printInfo()  {
    cout << "Dish: " << name << " | Price: " << price << " | Weight: " << weight << endl;
}

void Dish::show() {
    cout << "This is dish" << endl;
}