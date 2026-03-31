#include "Salad.h"
#include <iostream>
using namespace std;
Salad::Salad(string name, double price, double weight, string with, float cal ):Dish(name,price,weight)  {
    this->with=with;
    this->cal=cal;
}
Salad::~Salad() {};
void Salad::printInfo(){
    Dish::printInfo();
    cout<< " |With : " << with << " |Calories : " << cal << endl;
};

