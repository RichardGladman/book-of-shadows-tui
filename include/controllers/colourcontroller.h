#ifndef COLOURCONTROLLER_H
#define COLOURCONTROLLER_H

#pragma once

#include "controller.h"

#include <ncurses.h>

class ColourController : public Controller
{
public:
    static void start();

    ColourController();
    ~ColourController();

private:
    virtual std::shared_ptr<Menu> generate_menu() override;
    virtual void add_action() override;
    virtual void edit_action() override;
    virtual void view_action() override;
    virtual void delete_action() override;
};

#endif