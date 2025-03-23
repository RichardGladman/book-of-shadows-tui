#include "controllers/colourcontroller.h"

#include <memory>

void ColourController::start() {
    std::shared_ptr<ColourController> controller = std::make_shared<ColourController>();
    controller->run();
}

ColourController::ColourController()
{

}

ColourController::~ColourController()
{

}

void ColourController::add_action() {
    wprintw(Controller::s_main_window, "Colour Add Method");
    wrefresh(Controller::s_main_window);
}

void ColourController::edit_action() {
    wprintw(Controller::s_main_window, "Colour Edit Method");
    wrefresh(Controller::s_main_window);

}

void ColourController::view_action() {
    wprintw(Controller::s_main_window, "Colour View Method");
    wrefresh(Controller::s_main_window);

}

void ColourController::delete_action() {
    wprintw(Controller::s_main_window, "Colour Delete Method");
    wrefresh(Controller::s_main_window);

}

std::shared_ptr<Menu> ColourController::generate_menu() {
    
    std::shared_ptr<Menu> menu = std::make_shared<Menu>(Controller::s_menu_window);
    menu->header("Colours");

    std::shared_ptr<Option> add_new_option = std::make_shared<Option>(Controller::s_menu_window, "Add New", std::bind(&Controller::add_action, this), 1);
    std::shared_ptr<Option> edit_option = std::make_shared<Option>(Controller::s_menu_window, "Edit", std::bind(&Controller::edit_action, this), 2);
    std::shared_ptr<Option> view_option = std::make_shared<Option>(Controller::s_menu_window, "View", std::bind(&Controller::view_action, this), 3);
    std::shared_ptr<Option> delete_option = std::make_shared<Option>(Controller::s_menu_window, "Delete", std::bind(&Controller::delete_action, this), 4);
    std::shared_ptr<Option> back_option = std::make_shared<Option>(Controller::s_menu_window, "Back to Main", nullptr, 5);

    menu->add_option(add_new_option);
    menu->add_option(edit_option);
    menu->add_option(view_option);
    menu->add_option(delete_option);
    menu->add_option(back_option);

    return menu;
}