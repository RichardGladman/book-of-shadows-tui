#ifndef OPTION_H
#define OPTION_H

#pragma once

#include <functional>
#include <ncurses.h>
#include <string>

class Option
{
public:
    Option(WINDOW *window, const std::string &text, std::function<void()> action, int row);
    ~Option();

    int row() const;
    std::function<void()> action() const;

    void render(bool highlight=false) const;

private:
    WINDOW *m_window;
    std::string m_text;
    std::string m_render_text {};
    std::function<void()> m_action;

    int m_row {};
};

#endif