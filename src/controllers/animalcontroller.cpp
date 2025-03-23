#include "controllers/animalcontroller.h"

#include <memory>

void AnimalController::start() {
    std::shared_ptr<AnimalController> controller = std::make_shared<AnimalController>();
    controller->run();
}


AnimalController::AnimalController()
{

}

AnimalController::~AnimalController()
{

}

void AnimalController::add_action() {
    wprintw(Controller::s_main_window, "Animal Add Method");
    wrefresh(Controller::s_main_window);
}

void AnimalController::edit_action() {
    wprintw(Controller::s_main_window, "Animal Edit Method");
    wrefresh(Controller::s_main_window);

}

void AnimalController::view_action() {
    wprintw(Controller::s_main_window, "Animal View Method");
    wrefresh(Controller::s_main_window);

}

void AnimalController::delete_action() {
    wprintw(Controller::s_main_window, "Animal Delete Method");
    wrefresh(Controller::s_main_window);

}

std::shared_ptr<Menu> AnimalController::generate_menu() {
    
    std::shared_ptr<Menu> menu = std::make_shared<Menu>(Controller::s_menu_window);

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