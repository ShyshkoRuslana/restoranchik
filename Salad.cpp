#include "Salad.h"
#include <iostream>
using namespace std;
Salad::Salad(string name, double price, double weight, string with, float cal ):Dish(name,price,weight)  {
    this->with=with;
    this->cal=cal;
}
Salad::Salad(const Salad& other)
        : Dish(other) // копіюємо поля батька
{
    with = other.with;
    cal = other.cal;
}

// Move constructor
Salad::Salad(Salad&& other) noexcept
        : Dish(std::move(other)) // переносимо поля батька
{
    with = std::move(other.with);
    cal = other.cal;
}

// Copy assignment operator
Salad& Salad::operator=(const Salad& other)
{
    if (this != &other) {
        Dish::operator=(other); // копіюємо поля батька
        with = other.with;
        cal = other.cal;
    }
    return *this;
}
Salad::~Salad() {};
void Salad::printInfo(){
    Dish::printInfo();
    cout<< " |With : " << with << " |Calories : " << cal << endl;
};
