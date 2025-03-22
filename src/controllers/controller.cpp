#include "controllers/controller.h"

void Controller::set_main_window(WINDOW *window) {
    Controller::s_main_window = window;
}

void Controller::set_menu_window(WINDOW *window) {
    Controller::s_menu_window = window;
}

Controller::Controller()
{

}

Controller::~Controller()
{

}

void Controller::run() {
    std::shared_ptr<Menu> menu = generate_menu();
    menu->header("Animals");
    menu->clear();

    while (true) {
        menu->render();
        std::shared_ptr<Option> chosen = menu->select();

        if (chosen->action() == nullptr) break;
    }

    menu->clear();
}