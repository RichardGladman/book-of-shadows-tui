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

    virtual void add_action() = 0;
    virtual void edit_action() = 0;
    virtual void view_action() = 0;
    virtual void delete_action() = 0;
protected:
    inline static WINDOW *s_main_window;
    inline static WINDOW *s_menu_window;

    void run();
    virtual std::shared_ptr<Menu> generate_menu() = 0;

private:

};

#endif