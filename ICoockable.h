#ifndef ICOOCKABLE_H
#define ICOOCKABLE_H
#include <iostream>

class ICoockable {
public:
    virtual void cook()=0;
    virtual void serve()=0;
    virtual ~ICoockable();

};


#endif
