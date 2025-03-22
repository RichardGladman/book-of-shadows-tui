#ifndef ANIMALCONTROLLER_H
#define ANIMALCONTROLLER_H

#pragma once

#include "controller.h"

#include <ncurses.h>

class AnimalController : public Controller
{
public:
    static void start();
    
    AnimalController();
    ~AnimalController();
private:
    virtual std::shared_ptr<Menu> generate_menu() override;
};

#endif