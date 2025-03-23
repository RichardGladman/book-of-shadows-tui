#include <memory>
#include <iostream>
#include <ncurses.h>

#include "controllers/controller.h"
#include "controllers/animalcontroller.h"
#include "controllers/colourcontroller.h"
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

    box(main_window, 0, 0);

    wrefresh(menu_window);
    wrefresh(main_window);

    std::unique_ptr<Menu> menu = std::make_unique<Menu>(menu_window);
    menu->header("Main Menu");

    Controller::set_main_window(main_window);
    Controller::set_menu_window(menu_window);

    std::shared_ptr<Option> animals_option = std::make_shared<Option>(menu_window, "Animals", AnimalController::start, 1);
    std::shared_ptr<Option> colours_option = std::make_shared<Option>(menu_window, "Colours", ColourController::start, 2);
    std::shared_ptr<Option> quit_option = std::make_shared<Option>(menu_window, "Quit", nullptr, 3);

    menu->add_option(animals_option);
    menu->add_option(colours_option);
    menu->add_option(quit_option);

    menu->clear();

    while (true) {
        menu->render();
        std::shared_ptr<Option> option = menu->select();
    
        if (option->action() == nullptr) {
            break;
        }
        
        option->action()();
    }

    endwin();

    return 0;
}
