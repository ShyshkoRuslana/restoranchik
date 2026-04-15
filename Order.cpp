#include "Order.h"
#include "Dish.h"
#include <iostream>
using namespace std;

Order::Order():Order(0,0.0){}
Order::Order(int ordernumber):Order(ordernumber,0.0){}
Order::Order(int ordernumber, double totalsum):ordernumber(ordernumber),totalsum(totalsum) {}

Order::Order(const Order& other) {
       ordernumber=other.ordernumber;
       totalsum=other.totalsum;
       dishes = other.dishes;
}

Order::~Order() {}

void Order::printInfo() const {
    cout << "Order number: " << ordernumber << endl;
    cout << "Dishes:" << endl;
    for(const Dish& d : dishes) {
        d.printInfo();
    }
    cout << "Total sum: " << totalsum << endl;
}

Order Order::operator+(const Order& other) {
    return Order(ordernumber + other.ordernumber,totalsum + other.totalsum);
}
void Order::addDish(Dish d) {
    dishes.push_back(d);
    totalsum += d.getprice();
}