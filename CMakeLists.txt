cmake_minimum_required(VERSION 4.0)
project(restoranchik)

set(CMAKE_CXX_STANDARD 20)

add_executable(restoranchik main.cpp
        Dish.cpp
        Dish.h
        Customer.cpp
        Customer.h
        Order.cpp
        Order.h
        Salad.cpp
        Salad.h
        Menu.cpp
        Menu.h
        SpecialSalad.cpp
        SpecialSalad.h
        ICoockable.cpp
        ICoockable.h
        System.cpp
        System.h)
