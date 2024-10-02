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

void handle_events(int c, int* screen, bool* is_active) {
	switch (c) {
	case KEY_RESIZE:
		clear();
		select_draw_function(*screen);
		refresh();
		break;
	case ctrl('c'):
		*is_active = false;
		break;
	case ctrl('n'):
		if (*screen == 1)
			break;
		*screen = 1;
		clear();
		select_draw_function(*screen);
		refresh();
		break;
	default:
		break;
	}
}