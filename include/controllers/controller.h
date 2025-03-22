#ifndef CONTROLLER_H
#define CONTROLLER_H

#pragma once

#include <memory>
#include <ncurses.h>

#include "menu/menu.h"

class Controller
{
public:
    static void set_main_window(WINDOW *window);
    static void set_menu_window(WINDOW *window);

    Controller();
    ~Controller();

protected:
    inline static WINDOW *s_main_window;
    inline static WINDOW *s_menu_window;

    void run();

private:
    virtual std::shared_ptr<Menu> generate_menu() = 0;

};

#endif