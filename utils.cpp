#include "headers/editor-utils.h"
#include "headers/utils.h"

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