#include <curses.h>
#include "headers/editor-utils.h"
#include "headers/utils.h"

#define ctrl(x) (x & 0x1F)

void select_draw_function(int screen) {
	switch (screen) {
	case 0:
		welcome_screen();
		break;
	case 1:
		draw_rows();
		break;
	default:
		break;
	}
}

void handle_events(char c, int* screen, bool* is_active) {
	if (c == ctrl('c'))
		*is_active = false;
	if ((c == ctrl('n') || c == ctrl('N')) && *screen == 0) {
		*screen = 1;
		clear();
		select_draw_function(*screen);
		refresh();
	}
}