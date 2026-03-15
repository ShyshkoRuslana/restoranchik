#ifndef ORDER_H
#define ORDER_H
using namespace std;


class Order {
private:
    int ordernumber;
    double totalsum;
public:
    Order();
    Order(int ordernumber);
    Order(int ordernumber, double totalsum);


    ~Order();


    void printInfo()const;
};


#endif
