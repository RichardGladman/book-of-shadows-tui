#ifndef ANIMALCONTROLLER_H
#define ANIMALCONTROLLER_H

#pragma once

#include <ncurses.h>

class AnimalController
{
public:
    static WINDOW *s_window;
    
    static void test();
    
    AnimalController();
    ~AnimalController();

private:
};

#endif