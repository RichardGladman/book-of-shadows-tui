add_executable(bostui main.cpp
    controllers/controller.cpp
    controllers/animalcontroller.cpp controllers/colourcontroller.cpp controllers/godcontroller.cpp
    controllers/herbcontroller.cpp controllers/planetcontroller.cpp
    menu/menu.cpp menu/option.cpp)

target_include_directories(bostui PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(bostui PRIVATE ncurses)
