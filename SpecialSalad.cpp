#include "SpecialSalad.h"

SpecialSalad::SpecialSalad() {}
SpecialSalad::SpecialSalad(string name, double price, double weight,string with, float cal,string sauce, string spicy)
        : Salad(name, price, weight, with, cal)
{
    this->sauce = sauce;
    this->spicy = spicy;
}
SpecialSalad::~SpecialSalad() {}

void SpecialSalad::printInfo() {
    Salad::printInfo();
    cout << " | Sauce: " << sauce << " | Spicy: " << spicy <<  endl;
}
void SpecialSalad::getPrice() {
    cout << "Special salad price: " << price << endl;
}