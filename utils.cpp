#include <curses.h>
#include "headers/editor-utils.h"
#include "headers/utils.h"
#include "headers/curses-text-editor.h"

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

void print_characters(int tracker)
{
	clear();
	draw_rows();
	for (int i = 0; i < lines[tracker].size(); i++)
		printw("%c", lines[tracker].at(i));
	refresh();
}

void handle_events(int c, bool* is_active) {
	int tracker = 0;
	switch (c) {
	case KEY_RESIZE:
		clear();
		select_draw_function(screen);
		refresh();
		break;
	case ctrl('c'):
		*is_active = false;
		break;
	case ctrl('n'):
		if (screen == 1)
			break;
		screen = 1;
		clear();
		select_draw_function(screen);
		refresh();
		break;
	case KEY_UP:
		if (cursor_y > 0)
			move(--cursor_y, cursor_x);
		break;
	case KEY_DOWN:
		if (cursor_y < getmaxy(stdscr) - 1 && cursor_y < lines.size())
			move(++cursor_y, cursor_x);
		break;
	case KEY_RIGHT:
		if (cursor_x < getmaxx(stdscr) - 1)
			move(cursor_y, ++cursor_x);
		break;
	case KEY_LEFT:
		if (cursor_x > EDITOR_ROW_START)
			move(cursor_y, --cursor_x);
		break;
	case KEY_BACKSPACE:
		if (lines.size() != 0 && lines[tracker].size() != 0) {
			lines[tracker].pop_back();
			print_characters(tracker);
		}
		break;
	default:
		if (lines.size() == 0)
			lines.push_back("");
		lines[tracker].push_back((char)c);
		print_characters(tracker);
		break;
	}
}