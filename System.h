#ifndef RESTORANCHIK_SYSTEM_H
#define RESTORANCHIK_SYSTEM_H
#include "Menu.h"


class System{
private:
    Menu& menu;
    std::vector<Dish> dishes;
    string password = "1111";
public:
    System(Menu &m);
    void start();
    void addDish(const Dish& d);
    void printMenu();
    void updatedish();
    void deletedish();
    bool adminlogin();
    void adminmenu();
    void username();
    void usermenu();
    ~System();


};


#endif
