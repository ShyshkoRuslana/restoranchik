#ifndef SALAD_H
#define SALAD_H
#include "Dish.h"
#include <string>
using namespace std;

class Salad : public Dish{
protected:
    string with;
    float cal;
public:
    Salad();
    Salad(string name, double price, double weight, string with,float cal );
    Salad(const Salad& other);
    virtual ~Salad();
    Salad(Salad&& other);
    Salad& operator=(const Salad& other);

    void printInfo();
    void show();
    virtual void getName();
    virtual void getPrice();



};

#endif
