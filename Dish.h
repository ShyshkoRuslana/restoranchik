#ifndef DISH_H
#define DISH_H
#include <string>
using namespace std;
class Dish {
private:
    string name;
    double price;
    double weight;
public:
    Dish();
    Dish(string name);
    Dish(string name, double price);
    Dish(string name, double price, double weight);
    ~Dish();

    void printInfo();

};


#endif

