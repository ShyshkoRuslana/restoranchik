#ifndef MENU_H
#define MENU_H
#include <vector>
#include "Dish.h"
#include "Salad.h"

class Menu {
private:
    std::vector<Dish> dishes;
    int index;
public:
    void addDish(const Dish& d);
    void printMenu();
    void updatedish(int index, const Dish& d);
    void deletedish(int index);
};

#endif