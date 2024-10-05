#include <curses.h>
#include <iostream>
#include "headers/editor-utils.h"
#include "headers/utils.h"
#include "headers/curses-text-editor.h"

void initialize_screen() {
    select_draw_function(screen);
    refresh();
    bool is_active = true;
    while (is_active) {
        if (screen == 0)
            curs_set(0);
        else
            curs_set(2);
        int c = getch();
        handle_events(c, &is_active);
    }
}

void welcome_screen() {
    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);
    std::string welcome_mesage = "Welcome to Curses Text Editor";
    std::string options = "Press 'Ctrl + n' for new empty file";
    int len_welcome_message = welcome_mesage.length();
    mvprintw((y_max / 2) - 2, (x_max / 2 - len_welcome_message / 2), welcome_mesage.c_str());
    mvprintw((y_max / 2), (x_max / 2 - len_welcome_message / 2) - 3, options.c_str());
}

void draw_rows() {
    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);
    for (int i = 0; i < y_max; i++) 
        mvprintw(i, 0, "%d", i);
    move(cursor_y, cursor_x);
}