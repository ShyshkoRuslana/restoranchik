#ifndef MENU_H
#define MENU_H
#include <vector>
#include "Dish.h"
#include "Salad.h"

class Menu {
private:
    std::vector<Dish> dishes;   // для всіх простих страв

public:
    void addDish(const Dish& d);   // додаємо просту страву
    void printMenu();              // показати меню
};

#endif