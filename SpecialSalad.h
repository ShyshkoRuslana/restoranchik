#ifndef SPECIALSALAD_H
#define SPECIALSALAD_H
#include "Salad.h"

class SpecialSalad: public Salad{
private:
    string sauce;
    string spicy;
public:
    SpecialSalad(string name, double price, double weight, string with,float cal, string sause, string spicy);
    ~SpecialSalad();

    void printInfo();


};


#endif
