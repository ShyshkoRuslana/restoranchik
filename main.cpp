#include <iostream>
#include "Dish.h"
#include "Order.h"
#include "Customer.h"
using namespace std;
int main() {
    cout << "===Customer1===" << endl;
    Customer c1;
    c1.printInfo();
    cout << "-Dish-" << endl;
    Dish d1;
    d1.printInfo();
    cout << "-Order-" << endl;
    Order o1;
    o1.printInfo();
    cout << "-----------------------------" << endl;


    cout << "===Customer2===" << endl;
    Customer c2("Арінка");
    c2.printInfo();
    cout << "-Dish-" << endl;
    Dish d2("Вареники");
    d2.printInfo();
    cout << "-Order-" << endl;
    Order o2(34);
    o2.printInfo();
    cout << "-----------------------------" << endl;


    cout << "===Customer3===" << endl;
    Customer c3("Соня", 5);
    c3.printInfo();
    cout << "-Dish-" << endl;
    Dish d3("Олівє", 67);
    d3.printInfo();
    cout << "-Order-" << endl;
    Order o3(34, 6789);
    o3.printInfo();
    cout << "-----------------------------" << endl;


    cout << "===Customer4===" << endl;
    Customer c4("Ання", 9, 423);
    c4.printInfo();
    cout << "-Dish-" << endl;
    Dish d4("Борщ", 85.50, 300);
    d4.printInfo();
    cout << "-Order-" << endl;
    Order o4(23, 405);
    o4.printInfo();
    cout << "-----------------------------" << endl;


    cout << "===Customer5===" << endl;
    Customer c5 = c4;
    c5.printInfo();
    cout << "-----------------------------" << endl;


    cout << "===Customer6===" << endl;
    Customer c6 = move(c3);
    c6.printInfo();
    cout << "-----------------------------" << endl;


    cout << "===Dish operations===" << endl;
    Dish combo = d2 + d4;
    ++d2;
    cout << "Combo dish: " << combo << endl;
    cout << "Updated d2: " << d2 << endl;
    cout << "-----------------------------" << endl;


    cout << "===Order sum===" << endl;
    Order total = o3 + o4;
    total.printInfo();
    cout << "-----------------------------" << endl;


    cout << "===Customer7===" << endl;
    Dish d7;
    cout << "Enter dish (name price weight): ";
    cin >> d7;
    cout << "You entered: " << d7 << endl;
    cout << "-----------------------------" << endl;


    cout << "Total customers created:" << Customer::getcount() << endl;
    cout << "-----------------------------" << endl;

    return 0;
}
