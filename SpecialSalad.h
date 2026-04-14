#ifndef SPECIALSALAD_H
#define SPECIALSALAD_H
#include "Salad.h"
#include "ICoockable.h"

class SpecialSalad final : public Salad, public ICoockable{
private:
    string sauce;
    string spicy;
public:
    SpecialSalad();
    SpecialSalad(string name, double price, double weight, string with,float cal, string sause, string spicy);
    virtual ~SpecialSalad();

    void printInfo();
    void getName()override;
    void getPrice()override;
    void cook()override;
    void serve()override;

};
#endif
