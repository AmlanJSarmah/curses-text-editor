#include <curses.h>
#include <vector>
#include <string>
#include "headers/editor-utils.h"
#include "headers/curses-text-editor.h"

int screen = 0;
int tracker = 0;
std::vector<std::string> lines;

int main()
{
    initscr();
    raw();
    noecho();
    keypad(stdscr, true);

    initialize_screen();

    endwin();
	return 0;
}
