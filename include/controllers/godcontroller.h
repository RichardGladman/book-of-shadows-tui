#ifndef GODCONTROLLER_H
#define GODCONTROLLER_H

#pragma once

#include "controller.h"

#include <ncurses.h>

class GodController : public Controller
{
public:
    static void start();

    GodController();
    ~GodController();

protected:
    void search_action();

private:
    virtual std::shared_ptr<Menu> generate_menu() override;
    virtual void add_action() override;
    virtual void edit_action() override;
    virtual void view_action() override;
    virtual void delete_action() override;
};

#endif