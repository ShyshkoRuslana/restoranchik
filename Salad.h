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
    Salad(Salad&& other) noexcept;
    Salad& operator=(const Salad& other);

    ~Salad();
    void printInfo();
    void show();
    virtual void getPrice();



};

#endif
