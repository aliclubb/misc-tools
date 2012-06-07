#include <stdio.h>
#include <curses.h>
#include "levels.dat"

int level_completed(l, y, x, c)
{
	clear();
	getmaxyx(stdscr, y, x);
	mvprintw(y/2, x/4, "Congratulations, you have completed level %i\n", l);
	mvprintw((y/2)+1, x/4, "Would you like to [c]ontinue or [q]uit?");
	switch(c = getch())
	{
		case 'c' : draw_maze(l); break; // Continue and render next level.
		case 'q' : endwin(); break; // Close ncurses window
	}
	return 0;
}

int main (void)
{
	int level = 1, wall, c, y, x; // Set the level counter
	initscr();
	noecho();
	keypad(stdscr, TRUE); // Catch all user input
	raw();
	draw_maze(level); // Draw the maze
	getbegyx(stdscr, y, x);
	mvprintw(++y, ++x, "@");
	move(y, x); // Move the cursor so that it is on top of the character.
	refresh();
	while ((c = getch()) != 3) // Get user input while it is not equal to ^C
	{
		switch(c)
		{
			case KEY_UP :
			{
				move(--y, x); // Move the cursor up by one
				wall = inch();
				switch(wall)
				{
					case '.' : move(++y, x); break;
					case ' ' :
					{
						move(++y, x);
						addch(' ');
						move(--y, x);
						addch('@');
						move(y, x);
						break;
					}
					case 'o' : level_completed(level++); break;
				}
				refresh();
				break;
			}
			case KEY_DOWN :
			{
				move(++y, x);
				wall = inch();
				switch(wall)
				{
					case '.' : move(--y, x); break;
					case ' ' :
					{
						move(--y, x);
						addch(' ');
						move(++y, x);
						addch('@');
						move(y, x);
						break;
					}
					case 'o' : level_completed(level++); break;
				}
				refresh();
				break;
			}
			case KEY_LEFT :
			{
				move(y, --x);
				wall = inch();
				switch(wall)
				{
					case '.' : move(y, ++x); break;
					case ' ' :
					{
						move(y, ++x);
						addch(' ');
						move(y, --x);
						addch('@');
						move(y, x);
						break;
					}
					case 'o' : level_completed(level++); break;
				}
				refresh();
				break;
			}
			case KEY_RIGHT :
			{
				move(y, ++x);
				wall = inch();
				switch(wall)
				{
					case '.' : move(y, --x); break;
					case ' ' :
					{
						move(y, --x);
						addch(' ');
						move(y, ++x);
						addch('@');
						move(y, x);
						break;
					}
					case 'o' : level_completed(level++); break;
				}
				refresh();
				break;
			}
		}
	}
	endwin();
	return 0;
}