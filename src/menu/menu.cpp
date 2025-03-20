#include "menu/menu.h"

Menu::Menu(WINDOW *window) {
    m_window = window;
    box(m_window, 0, 0);
    keypad(m_window, true);
    wrefresh(m_window);
}

Menu::~Menu() {}

std::string Menu::header() const {
    return m_header;
}

void Menu::header(const std::string& title) {
    m_header = title;
}

void Menu::add_option(std::shared_ptr<Option> option) {
    m_options.push_back(option);
}

std::shared_ptr<Option> Menu::select() {
    int choice {};

    while (choice != 10) {

        render();
        choice = wgetch(m_window);
        
        switch (choice) {
            case KEY_UP:
                --m_highlighted;
                if (m_highlighted < 0) m_highlighted = 0;
                break;
            case KEY_DOWN:
                ++m_highlighted;
                if (m_highlighted >= m_options.size()) m_highlighted = m_options.size() - 1;
                break;
        }
    }

    return m_options[m_highlighted];
}

void Menu::render() const {
    mvwprintw(m_window, 0, 2, m_header.c_str());
    
    for (size_t i=0; i<m_options.size(); ++i) {
        const Option option = *m_options.at(i);
        if (m_highlighted == i) {
            option.render(true);
        } else {
            option.render(false);
        }
    }
    
    wrefresh(m_window);
}

void Menu::invoke(int selection) const {
    for (int i {0}; i < m_options.size(); ++i) {
        const Option option = *m_options.at(i);
        std::function<void()> func = option.action();
        if (func != nullptr) {
            func();
        }
    }
}