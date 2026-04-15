#ifndef ORDER_H
#define ORDER_H
#include "Dish.h"
using namespace std;

class Order {
private:

    int ordernumber;
    double totalsum;
public:
    std::vector<Dish> dishes;
    Order();
    Order(int ordernumber);
    Order(int ordernumber, double totalsum);

    Order(const Order& other);

    ~Order();

    Order operator+(const Order& other);

    void printInfo()const;
    void addDish(Dish);
};
#endif
