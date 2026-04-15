#ifndef RESTORANCHIK_SYSTEM_H
#define RESTORANCHIK_SYSTEM_H
#include "Menu.h"
#include "Order.h"


class System{
private:
    Menu& menu;
    std::vector<Dish> dishes;
    std::vector<Order> orders;
    string password = "1111";
    int nextorderId = 1;
public:
    System(Menu &m);
    void start();
    void addDish(const Dish& d);
    void printMenu();
    void updatedish();
    void deletedish();
    bool adminlogin();
    void adminmenu();
    void makeorder();
    void showorder();
    void usermenu();
    ~System();


};


#endif
