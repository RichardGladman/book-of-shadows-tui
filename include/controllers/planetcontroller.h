#ifndef PLANETCONTROLLER_H
#define PLANETCONTROLLER_H

#pragma once

#include "controller.h"

#include <ncurses.h>

class PlanetController : public Controller
{
public:
    static void start();

    PlanetController();
    ~PlanetController();

private:
    virtual std::shared_ptr<Menu> generate_menu() override;
    virtual void add_action() override;
    virtual void edit_action() override;
    virtual void view_action() override;
    virtual void delete_action() override;
};

#endif