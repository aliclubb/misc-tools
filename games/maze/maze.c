#include <stdio.h>
#include <curses.h>
#include "game_features.h"
#include "levels.dat"

int main (void)
{
	int level = 1, have_key = 0, wall, c, y, x; // Set the level counter
	x = y = 1;
	initscr();
	noecho();
	keypad(stdscr, TRUE); // Catch all user input
	raw();
	draw_maze(level); // Draw the maze
	mvprintw(1, 1, "@");
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
							unlock();
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
							unlock();
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
							unlock();
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