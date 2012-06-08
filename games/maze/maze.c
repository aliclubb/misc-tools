#include <stdio.h>
#include <curses.h>
#include "levels.dat"
#include "game_features.h"

void level_completed(int level)
{
	int y, x;
	clear();
	getmaxyx(stdscr, y, x);
	mvprintw(y/2, x/4, "Congratulations, you have completed level %i\n", level);
	mvprintw((y/2)+1, x/4, "Would you like to [c]ontinue or [q]uit?");
}

int main (void)
{
	int level = 1, have_key = 0, wall, c, y, x; // Set the level counter
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
				switch(wall = inch())
				{
					case '#' : move(++y, x); break;
					case '+' :
					{
						if(have_key == 1)
						{
							addch(' ');
							move(22, 0);
							deleteln();
							mvprintw(22, 0, "The rusty key creaked in the lock... The key snapped! The door opened....");
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
						move(y, x);
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
				break;
			}
			case KEY_DOWN :
			{
				move(++y, x);
				switch(wall = inch())
				{
					case '#' : move(--y, x); break;
					case '+' :
					{
						if(have_key == 1)
						{
							addch(' ');
							move(22, 0);
							deleteln();
							mvprintw(22, 0, "The rusty key creaked in the lock... The key snapped! The door opened....");
							have_key--;
							move(--y, x);
						}
						else
						{
							move(22, 0);
							deleteln();
							mvprintw(22, 0, "This door appears to be locked.... You need a key.");
							move(--y, x);
						}
						break;
					}
					case ' ' :
					{
						move(--y, x);
						addch(' ');
						move(++y, x);
						addch('@');
						move(y, x);
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
						move(--y, x);
						addch(' ');
						move(++y, x);
						addch('@');
						move(y, x);
						break;
					}
				}
				refresh();
				break;
			}
			case KEY_LEFT :
			{
				move(y, --x);
				switch(wall = inch())
				{
					case '#' : move(y, ++x); break;
					case '+' :
					{
						if(have_key == 1)
						{
							addch(' ');
							move(22, 0);
							deleteln();
							mvprintw(22, 0, "The rusty key creaked in the lock... The key snapped! The door opened....");
							have_key--;
							move(y, ++x);
						}
						else
						{
							move(22, 0);
							deleteln();
							mvprintw(22, 0, "This door appears to be locked.... You need a key.");
							move(y, ++x);
						}
						break;
					}
					case ' ' :
					{
						move(y, ++x);
						addch(' ');
						move(y, --x);
						addch('@');
						move(y, x);
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
						move(y, ++x);
						addch(' ');
						move(y, --x);
						addch('@');
						move(y, x);
						break;
					}
				}
				refresh();
				break;
			}
			case KEY_RIGHT :
			{
				move(y, ++x);
				switch(wall = inch())
				{
					case '#' : move(y, --x); break;
					case '+' :
					{
						if(have_key == 1)
						{
							addch(' ');
							move(22, 0);
							deleteln();
							mvprintw(22, 0, "The rusty key creaked in the lock... The key snapped! The door opened....");
							have_key--;
							move(y, --x);
						}
						else
						{
							move(22, 0);
							deleteln();
							mvprintw(22, 0, "This door appears to be locked.... You need a key.");
							move(y, --x);
						}
						break;
					}
					case ' ' :
					{
						move(y, --x);
						addch(' ');
						move(y, ++x);
						addch('@');
						move(y, x);
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
						move(y, --x);
						addch(' ');
						move(y, ++x);
						addch('@');
						move(y, x);
						break;
					}
				}
				refresh();
				break;
			}
		}
	}
	endwin();
	return 0;
}