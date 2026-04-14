#ifndef MENU_H
#define MENU_H
#include <vector>
#include "Dish.h"
#include "Salad.h"

class Menu {
private:
    std::vector<Dish*> dishes;
public:
    void addDish(const Dish& d);
    void printMenu();
};

#endif