#include <curses.h>
#include "headers/editor-utils.h"

int screen = 1;

int main()
{
    initscr();
    raw();
    noecho();

    initialize_screen(&screen);

    getch();
    endwin();
	return 0;
}
