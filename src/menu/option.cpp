#include "menu/option.h"

#include <iostream>
#include <ncurses.h>

Option::Option(WINDOW *window, const std::string &text, std::function<void()> action, int row) :
    m_window {window}, m_text {text}, m_action {action}, m_row {row} {
        int max_x = getmaxx(window);

        std::string l_spaces((int)(max_x - m_text.size()) / 2, ' ');
        std::string r_spaces((int)(max_x - m_text.size()) / 2, ' ');
        m_render_text = l_spaces + m_text + r_spaces;

        if (m_render_text.length() >= max_x - 2) {
            m_render_text = m_render_text.substr(0, m_render_text.length() - 2);
        }
    
    }

Option::~Option() {}

std::function<void()> Option::action() const {
    return m_action;
}

int Option::row() const {
    return m_row;
}

void Option::render(bool highlight) const {

    if (highlight) {
        wattron(m_window, A_REVERSE);
    }

    mvwprintw(m_window, m_row, 1, m_render_text.c_str());

    if (highlight) {
        wattroff(m_window, A_REVERSE);
    }
}