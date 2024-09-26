#include <curses.h>
#include <iostream>
#include "headers/utils.h"

void initialize_screen() {
    initscr();
    raw();
    noecho();

    welcome_screen();

    getch();
    endwin();
}

void welcome_screen() {
    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);
    std::string welcome_mesage = "Welcome to Curses Text Editor";
    std::string options = "Press N for new empty file";
    int len_welcome_message = welcome_mesage.length();
    mvprintw((y_max / 2) - 2, (x_max / 2 - len_welcome_message / 2), welcome_mesage.c_str());
    mvprintw((y_max / 2), (x_max / 2 - len_welcome_message / 2) + 1, options.c_str());
}