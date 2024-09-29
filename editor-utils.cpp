#include <curses.h>
#include <iostream>
#include "headers/editor-utils.h"
#include "headers/utils.h"

#define ctrl(x) (x & 0x1F)

void initialize_screen(int* screen) {
    while (true) {
        select_draw_function(*screen);
        refresh();
        char c = getch();
        if (c == ctrl('c'))
            break;
        if (c == ctrl('n') || c == ctrl('N'))
            *screen = 1;
        clear();
    }
}

void welcome_screen() {
    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);
    std::string welcome_mesage = "Welcome to Curses Text Editor";
    std::string options = "Press 'Ctrl + N' for new empty file";
    int len_welcome_message = welcome_mesage.length();
    mvprintw((y_max / 2) - 2, (x_max / 2 - len_welcome_message / 2), welcome_mesage.c_str());
    mvprintw((y_max / 2), (x_max / 2 - len_welcome_message / 2) - 3, options.c_str());
}

void draw_rows() {
    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);
    for (int i = 0; i < y_max; i++) {
        move(i, 0);
        printw("%d", i);
    }
    move(0, 1);
}