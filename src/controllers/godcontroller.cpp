#include "controllers/godcontroller.h"

#include <memory>

void GodController::start() {
    std::shared_ptr<GodController> controller = std::make_shared<GodController>();
    controller->run();
}

GodController::GodController()
{

}

GodController::~GodController()
{

}

void GodController::add_action() {
    wprintw(Controller::s_main_window, "God Add Method");
    wrefresh(Controller::s_main_window);
}

void GodController::edit_action() {
    wprintw(Controller::s_main_window, "God Edit Method");
    wrefresh(Controller::s_main_window);

}

void GodController::view_action() {
    wprintw(Controller::s_main_window, "God View Method");
    wrefresh(Controller::s_main_window);

}

void GodController::delete_action() {
    wprintw(Controller::s_main_window, "God Delete Method");
    wrefresh(Controller::s_main_window);

}

void GodController::search_action() {
    wprintw(GodController::s_main_window, "God Search Method");
    wrefresh(GodController::s_main_window);

}

std::shared_ptr<Menu> GodController::generate_menu() {
    
    std::shared_ptr<Menu> menu = std::make_shared<Menu>(Controller::s_menu_window);
    menu->header("Gods");

    std::shared_ptr<Option> search_option = std::make_shared<Option>(GodController::s_menu_window, "Search", std::bind(&GodController::search_action, this), 1);
    std::shared_ptr<Option> add_new_option = std::make_shared<Option>(Controller::s_menu_window, "Add New", std::bind(&Controller::add_action, this), 2);
    std::shared_ptr<Option> edit_option = std::make_shared<Option>(Controller::s_menu_window, "Edit", std::bind(&Controller::edit_action, this), 3);
    std::shared_ptr<Option> view_option = std::make_shared<Option>(Controller::s_menu_window, "View", std::bind(&Controller::view_action, this), 4);
    std::shared_ptr<Option> delete_option = std::make_shared<Option>(Controller::s_menu_window, "Delete", std::bind(&Controller::delete_action, this), 5);
    std::shared_ptr<Option> back_option = std::make_shared<Option>(Controller::s_menu_window, "Back to Main", nullptr, 6);

    menu->add_option(search_option);
    menu->add_option(add_new_option);
    menu->add_option(edit_option);
    menu->add_option(view_option);
    menu->add_option(delete_option);
    menu->add_option(back_option);

    return menu;
}