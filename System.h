#ifndef RESTORANCHIK_SYSTEM_H
#define RESTORANCHIK_SYSTEM_H
#include "Menu.h"
#include "Order.h"
#include "Customer.h"


class System{
private:
    Menu& menu;
    std::vector<Dish> dishes;
    std::vector<Order> orders;
    vector<shared_ptr<Customer>> customers;
    string password = "1111";
    int nextorderId = 1;
    string action;
public:
    System(Menu &m);
    void start();
    void addDish(const Dish& d);
    void printMenu();
    void updatedish();
    void deletedish();
    bool adminlogin();
    void adminmenu();
    void createcustomer();
    void makeorder();
    void showorder();
    void usermenu();
    shared_ptr<Customer>customerlogin();
    void loadcustomer();
    void savecustomer();
    void saveorder();
    void loadorder();
    void savehistory(string action);
    void showhistory();
    ~System();


};


#endif
