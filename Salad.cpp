#include "Salad.h"
#include <iostream>
using namespace std;
Salad::Salad() {}
Salad::Salad(string name, double price, double weight, string with, float cal ):Dish(name,price,weight)  {
    this->with=with;
    this->cal=cal;
}
Salad::Salad(const Salad& other)
        : Dish(other)
{
    with = other.with;
    cal = other.cal;
}

Salad::Salad(Salad&& other) noexcept
        : Dish(std::move(other))
{
    with = std::move(other.with);
    cal = other.cal;
}
Salad& Salad::operator=(const Salad& other)
{
    if (this != &other) {
        Dish::operator=(other);
        with = other.with;
        cal = other.cal;
    }
    return *this;
}
Salad::~Salad() {}

void Salad::printInfo(){
    Dish::printInfo();
    cout<< " |With : " << with << " |Calories : " << cal << endl;
}
void Salad::show() {
    cout << "This is salad" << endl;
}
void Salad::getName() {
    cout << "name salad: " << name << endl;
}
void Salad::getPrice() {
    cout << "salad price: " << price << endl;
}
