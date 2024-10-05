#include <curses.h>
#include <vector>
#include <string>
#include "headers/editor-utils.h"
#include "headers/curses-text-editor.h"

int screen = 0;
int cursor_x = EDITOR_ROW_START;
int cursor_y = 0;
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
