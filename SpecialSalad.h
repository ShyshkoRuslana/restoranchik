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
    ~SpecialSalad();

    void printInfo();
    virtual void getName()override;
    virtual void getPrice() override;
    virtual void cook()override;
    virtual void serve()override;


};


#endif
