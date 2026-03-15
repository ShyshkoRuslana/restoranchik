#include "Customer.h"
#include <iostream>
#include <string>
Customer::Customer()
        : Customer("Guest", 1, 0) {}


Customer::Customer(string name, int tablenumber, int telnumber)
        :name(name), tablenumber(tablenumber), telnumber(telnumber) {}


Customer::Customer (const Customer& other){
    name=name;
    tablenumber=tablenumber;
    telnumber=telnumber;}