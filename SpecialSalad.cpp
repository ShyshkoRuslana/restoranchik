#include "SpecialSalad.h"
#include "ICoockable.h"

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
void SpecialSalad::getName() {
    cout << "Name Special salad: " << name << endl;
}
void SpecialSalad::getPrice() {
    cout << "Price Special salad: " << price << endl;
}
void SpecialSalad::cook() {
    cout << "Mix: " << with << "add add special sauce: " << sauce << endl;
}
void SpecialSalad::serve() {
    cout << "Serve special salad: " << name << endl;
}