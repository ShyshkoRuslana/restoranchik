#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Order.h"
#include <string>
#include <vector>
using namespace std;

class Customer {
private:
    string name;
    string surname;
    string login;
    int tablenumber;
    int telnumber;
    static int count;

    vector<Order> orders;
public:
    Customer();
    Customer(string name, int tablenumber=1, int telnumber=0);
    Customer(string name,string surname, string login);

    Customer(const Customer& other);
    Customer(Customer&& other);

    ~Customer();

    void addOrder(const Order& o);
    void printOrder();

    void printInfo()const;
    static int getcount();
    string getname()const;
    string getsurname()const;
    string getlogin()const;


};
#endif



