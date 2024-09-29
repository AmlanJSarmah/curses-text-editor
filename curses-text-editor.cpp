#include <curses.h>
#include "headers/editor-utils.h"

int screen = 0;

int main()
{
    initscr();
    raw();
    noecho();

    initialize_screen(&screen);

    endwin();
	return 0;
}
