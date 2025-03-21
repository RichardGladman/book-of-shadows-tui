#include <memory>
#include <iostream>
#include <ncurses.h>

#include "controllers/animalcontroller.h"
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
    WINDOW *main_window = newwin(y_max-8, x_max-24, 2, 2);

    box(menu_window, 0, 0);
    box(main_window, 0, 0);

    wrefresh(menu_window);
    wrefresh(main_window);

    std::unique_ptr<Menu> menu = std::make_unique<Menu>(menu_window);
    menu->header("Main Menu");

    AnimalController::s_window = main_window;

    std::shared_ptr<Option> animals_option = std::make_shared<Option>(menu_window, "Animals", AnimalController::test, 1);
    std::shared_ptr<Option> colours_option = std::make_shared<Option>(menu_window, "Colours", nullptr, 2);

    menu->add_option(animals_option);
    menu->add_option(colours_option);

    while (true) {
        menu->render();
        std::shared_ptr<Option> option = menu->select();
    
        if (option->action() != nullptr) {
            option->action()();
        } else {
            break;
        }

    }



    getch();
    endwin();

    return 0;
}
