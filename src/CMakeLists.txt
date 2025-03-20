add_executable(bostui main.cpp
    menu/menu.cpp menu/option.cpp)

target_include_directories(bostui PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(bostui PRIVATE ncurses)
