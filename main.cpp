#include <iostream>
#include "Dish.h"
#include "Order.h"
#include "Customer.h"
#include "Salad.h"
#include "Menu.h"
#include "SpecialSalad.h"
using namespace std;
int main() {
    Menu menu;

    cout << "===Customer1===" << endl;
    Customer c1;
    c1.printInfo();
    cout << "-Dish-" << endl;
    Dish d1;
    menu.addDish(d1);
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
    menu.addDish(d2);
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
    menu.addDish(d3);
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
    menu.addDish(d4);
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
    Customer c6 =std::move(c3);
    c6.printInfo();
    cout << "-----------------------------" << endl;

    cout << "===Dish operations===" << endl;
    Dish combo = d2 + d4;
    ++d2;
    menu.addDish(combo);
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
    menu.addDish(d7);
    cout << "You entered: " << d7 << endl;
    cout << "-----------------------------" << endl;


    cout << "Total customers created:" << Customer::getcount() << endl;
    cout << "-----------------------------" << endl;


    cout << "-----------------------------" << endl;
    Salad s1 ("цезар", 345,670, "chiken", 678);
    s1.printInfo();

    Salad s2=s1;
    s2.printInfo();

    Salad s3("Грецький", 150, 250, "курка", 400);
    Salad s4= std::move(s3);
    s4.printInfo();

    Salad s5("Королівський", 150, 250, "криветки", 400);
    s5.printInfo();
    s5=s4;
    s5.printInfo();

    menu.printMenu();

    Customer c10("Маруся", 5, 123);

    Order o11(1, 200);
    c10.addOrder(o11);
    Order o12(2, 350);
    c10.addOrder(o12);

    c10.printOrder();
    cout << "-----------------------------" << endl;

    SpecialSalad s67("Цезар", 200, 300, "курка", 500, "часниковий", "yes");
    s67.printInfo();

    Dish* d = new Salad();
    d->show();

    Salad* s = new SpecialSalad("Цезар", 200, 300, "курка", 500, "часниковий", "yes");
    s->getName();
    s->getPrice();

    SpecialSalad special("грецький", 450, 340, "оливки", 290, "майонез", "no");
    Salad& s_ref=special;//посилання на абстрактний клас
    s_ref.getName();
    s_ref.getPrice();








    return 0;
}
