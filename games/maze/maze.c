#include <stdio.h>
#include <curses.h>
#include "levels.dat"

int main (void)
{
	int level, wall, c, y, x;
	level = 1; // Set the level counter
	initscr();
	noecho();
	keypad(stdscr, TRUE); // Catch all user input
	raw();
	draw_maze(level); // Draw the maze
	getbegyx(stdscr, y, x);
	mvprintw(y+1, x+1, "@");
	refresh();
	getyx(stdscr, y, x); // Move the cursor so that it is on top of the character.
	x--;
	move(y, x);
	refresh();
	while ((c = getch()) != 3) // Get user input while it is not equal to ^C
	{
		switch(c)
		{
			case KEY_UP :
			{
				y--; // Move the cursor up by one
				move(y, x);
				wall = inch();
				switch(wall)
				{
					case '.' :
					{
						y++;
						move(y, x);
						refresh();
						break;	
					}
					case ' ' :
					{
						y++;
						move(y, x);
						delch();
						insch(' ');
						refresh();
						y--;
						move(y, x);
						addch('@');
						refresh();
						move(y, x);
						refresh();
						break;
					}
					case 'o' :
					{
						clear();
						getmaxyx(stdscr, y, x);
						mvprintw(y/2, x/4, "Congratulations, you have completed level %i\n", level);
						mvprintw((y/2)+1, x/4, "Would you like to [c]ontinue or [q]uit?");
						c = getch();
						switch(c)
						{
							case 'c' : break;
							case 'q' : endwin(); return 0; break;
						}
						draw_maze(level);
						level++;
						break;
					}
				}
				break;
			}
			case KEY_DOWN :
			{
				y++;
				move(y, x);
				wall = inch();
				switch(wall)
				{
					case '.' :
					{
						y--;
						move(y, x);
						refresh();
						break;
					}
					case ' ' :
					{
						y--;
						move(y, x);
						delch();
						insch(' ');
						refresh();
						y++;
						move(y, x);
						addch('@');
						refresh();
						move(y, x);
						refresh();
						break;
					}
					case 'o' :
					{
						clear();
						getmaxyx(stdscr, y, x);
						mvprintw(y/2, x/4, "Congratulations, you have completed level %i\n", level);
						mvprintw((y/2)+1, x/4, "Would you like to [c]ontinue or [q]uit?");
						c = getch();
						switch(c)
						{
							case 'c' : break;
							case 'q' : endwin(); return 0; break;
						}
						draw_maze(level);
						level++;
						break;
					}
				}
				break;
			}
			case KEY_LEFT :
			{
				x--;
				move(y, x);
				wall = inch();
				switch(wall)
				{
					case '.' :
					{
						x++;
						move(y, x);
						refresh();
						break;
					}
					case ' ' :
					{
						x++;
						move(y, x);
						delch();
						insch(' ');
						getyx(stdscr, y, x);
						x--;
						move(y, x);
						addch('@');
						refresh();
						move(y, x);
						refresh();
						break;
					}
					case 'o' :
					{
						clear();
						getmaxyx(stdscr, y, x);
						mvprintw(y/2, x/4, "Congratulations, you have completed level %i\n", level);
						mvprintw((y/2)+1, x/4, "Would you like to [c]ontinue or [q]uit?");
						c = getch();
						switch(c)
						{
							case 'c' : break;
							case 'q' : endwin(); return 0; break;
						}
						draw_maze(level);
						level++;
						break;
					}
				}
				break;
			}
			case KEY_RIGHT :
			{
				x++;
				move(y, x);
				wall = inch();
				switch(wall)
				{
					case '.' :
					{
						x--;
						move(y, x);
						refresh();
						break;
					}
					case ' ' :
					{
						x--;
						move(y, x);
						delch();
						insch(' ');
						getyx(stdscr, y, x);
						x++;
						move(y, x);
						addch('@');
						refresh();
						move(y, x);
						refresh();
						break;
					}
					case 'o' :
					{
						clear();
						getmaxyx(stdscr, y, x);
						mvprintw(y/2, x/4, "Congratulations, you have completed level %i\n", level);
						mvprintw((y/2)+1, x/4, "Would you like to [c]ontinue or [q]uit?");
						c = getch();
						switch(c)
						{
							case 'c' : break;
							case 'q' : endwin(); return 0; break;
						}
						draw_maze(level);
						level++;
						break;
					}
				}
				break;
			}
		}
		refresh();
	}
	endwin();
	return 0;
}