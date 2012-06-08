#include <curses.h>

void level_completed(int level)
{
	int y, x;
	clear();
	getmaxyx(stdscr, y, x);
	mvprintw(y/2, x/4, "Congratulations, you have completed level %i\n", level);
	mvprintw((y/2)+1, x/4, "Would you like to [c]ontinue or [q]uit?");
}

void unlock(void)
{
	addch(' ');
	move(22, 0);
	deleteln();
	mvprintw(22, 0, "The rusty key creaked in the lock... The key snapped! The door opened....");
}