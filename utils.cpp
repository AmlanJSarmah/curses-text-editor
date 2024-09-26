#include <curses.h>
#include <iostream>
#include "headers/utils.h"

void initialize_screen() {
    initscr();
    raw();
    noecho();
    
    move(0, 0);
    printw("Hello World");

    getch();
    endwin();
}