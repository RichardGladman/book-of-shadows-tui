#include <memory>
#include <iostream>
#include <ncurses.h>

#include "menu/menu.h"
#include "menu/option.h"

int main()
{
    initscr();
    noecho();
    curs_set(0);
    cbreak();

    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);

    WINDOW *menu_window = newwin(y_max-4, 18, 2, x_max-20);

    std::unique_ptr<Menu> menu = std::make_unique<Menu>(menu_window);
    menu->header("Main Menu");

    std::shared_ptr<Option> animals_option = std::make_shared<Option>(menu_window, "Animals", nullptr, 1);
    std::shared_ptr<Option> colours_option = std::make_shared<Option>(menu_window, "Colours", nullptr, 2);

    menu->add_option(animals_option);
    menu->add_option(colours_option);

    menu->select();

    getch();
    endwin();

    return 0;
}
