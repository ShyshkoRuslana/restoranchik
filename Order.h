#ifndef ORDER_H
#define ORDER_H
#include "Dish.h"
#include <vector>
using namespace std;

class Order {
private:
    std::vector<Dish> dishes;
    int ordernumber;
    double totalsum;
public:

    std::vector<Order>orders;
    Order();
    Order(int ordernumber);
    Order(int ordernumber, double totalsum);
    ~Order();

    Order operator+(const Order& other);
    Order(const Order& other);

    void printInfo()const;
    void addDish(Dish);
    int getId()const;
    vector <Dish> getDishes()const;
    double getTotal()const;
};
#endif
