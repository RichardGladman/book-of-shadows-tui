#ifndef MENU_H
#define MENU_H

#pragma once

#include <memory>
#include <string>
#include <ncurses.h>
#include <vector>

#include "menu/option.h"

class Menu
{
public:
    Menu(WINDOW *window);
    ~Menu();

    std::string header() const;
    void header(const std::string& title);

    void add_option(std::shared_ptr<Option> option);
    std::shared_ptr<Option> select();
    void render() const;
    void invoke(int selection) const;

private:
    WINDOW *m_window {};
    std::vector<std::shared_ptr<Option>> m_options {};
    std::string m_header {};
    int m_selected {-1};
    int m_highlighted {};
};

#endif