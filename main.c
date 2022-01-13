#include <stdio.h>
#include <ncurses.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "");
	initscr();

	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	init_pair(6, init_color(1, 243, 152, 0), COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
	bkgd(COLOR_PAIR(1));

	erase();
	attron(COLOR_PAIR(1) | A_REVERSE | A_BOLD);
	mvaddstr(5, 20, "        ");

	attron(COLOR_PAIR(2) | A_REVERSE | A_BOLD);
	mvaddstr(8, 20, "    ");
	mvaddstr(9, 20, "    ");

	attron(COLOR_PAIR(3) | A_REVERSE | A_BOLD);
	mvaddstr(12, 22, "    ");
	mvaddstr(13, 20, "    ");

	attron(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
	mvaddstr(16, 20, "    ");
	mvaddstr(17, 22, "    ");

	attron(COLOR_PAIR(5) | A_REVERSE | A_BOLD);
	mvaddstr(20, 20, "  ");
	mvaddstr(21, 20, "      ");

	attron(COLOR_PAIR(6) | A_REVERSE | A_BOLD);
	mvaddstr(24, 24, "  ");
	mvaddstr(25, 20, "      ");

	attron(COLOR_PAIR(7) | A_REVERSE | A_BOLD);
	mvaddstr(28, 22, "  ");
	mvaddstr(29, 20, "      ");

	refresh();

	timeout(-1);
	getch();

	endwin();
	return(0);
}
