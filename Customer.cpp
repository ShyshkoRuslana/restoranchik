#include "Customer.h"
#include <iostream>
#include <string>
int Customer::count=0;
Customer::Customer()
        : Customer("Guest", 1, 0) {}

Customer::Customer(string name, int tablenumber, int telnumber)
        :name(name), tablenumber(tablenumber), telnumber(telnumber) {count++;}

Customer::Customer(const Customer& other) {
         name=other.name;
         tablenumber=other.tablenumber;
         telnumber=other.telnumber;
         count++;
}
Customer::Customer(const Customer&& other){
        name=move(other.name);
        tablenumber=other.tablenumber;
        telnumber=other.telnumber;

        other.tablenumber=0;
        other.telnumber=0;
        count++;
}
Customer::~Customer() {}

void Customer::printInfo()const{
    cout << "Name: " << name << " | Table namber: " << tablenumber << " | Telephone number: " << telnumber << endl;
}
int Customer::getcount() {
    return count;
}
