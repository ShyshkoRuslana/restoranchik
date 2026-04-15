#ifndef RESTORANCHIK_SYSTEM_H
#define RESTORANCHIK_SYSTEM_H
#include "Menu.h"


class System {
private:
    Menu menu;
public:
    void start();
    void adminlogin();
    void adminmenu();
    void username();
    void usermenu();
    ~System();


};


#endif
