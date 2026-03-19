#include "Order.h"
#include <iostream>
using namespace std;

Order::Order():Order(0,0.0){}
Order::Order(int ordernumber):Order(ordernumber,0.0){}
Order::Order(int ordernumber, double totalsum):ordernumber(ordernumber),totalsum(totalsum) {}

Order::Order(const Order& other) {
       ordernumber=other.ordernumber;
       totalsum=other.totalsum;}

Order::~Order() {}

void Order::printInfo()const{
    cout << "Order number: " << ordernumber << " | Total sum: " << totalsum << endl;}

Order Order::operator+(const Order& other) {
    return Order(ordernumber + other.ordernumber,totalsum + other.totalsum);}