#include <curses.h>
#include "game_features.h"

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

int process_key_up(int y, int x, int level, int have_key)
{
	int wall, c;
	move(--y, x); // Move the cursor up by one
	switch(wall = inch())
	{
		case '#' : move(++y, x); break;
		case '+' :
		{
			if(have_key == 1)
			{
				unlock();
				have_key--;
				move(++y, x);
			}
			else
			{
				move(22, 0);
				deleteln();
				mvprintw(22, 0, "This door appears to be locked.... You need a key.");
				move(++y, x);
			}
			break;
		}
		case ' ' :
		{
			move(++y, x);
			addch(' ');
			move(--y, x);
			addch('@');
			move(++y, x);
			break;
		}
		case 'o' :
		{
			level_completed(level++);
			switch(c = getch())
			{
				case 'c' : draw_maze(++level); break; // Continue and render next level.
				case 'q' : endwin(); return 0; break; // Close ncurses window
			}
			break;
		}
		case 'E' :
		{
			have_key++;
			move(22, 0);
			deleteln();
			mvprintw(22, 0, "You picked up a rusty key....");
			move(++y, x);
			addch(' ');
			move(--y, x);
			addch('@');
			move(y, x);
			break;
		}
	}
	refresh();
	return(y);
	return(x);
}