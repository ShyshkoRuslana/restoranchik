#ifndef DISH_H
#define DISH_H
#include <string>
#include <iostream>
using namespace std;

class Dish{
protected:
    string name;
    double price;
    double weight;
public:
    Dish();
    Dish(string name);
    Dish(string name, double price);
    Dish(string name, double price, double weight);
    Dish(const Dish& other);
    Dish( Dish&& other);
    virtual ~Dish();
    void printInfo() ;
    void show();

    Dish operator+(const Dish& other);
    Dish operator++();
    Dish& operator=(const Dish& other)= default;

    friend ostream& operator<<(ostream& out, const Dish& d);
    friend istream& operator>>(istream& in, Dish& d);

};
#endif

