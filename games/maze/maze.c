#include <stdio.h>
#include <curses.h>
#include "levels.dat"

int main (void)
{
	int level, wall, c, y, x;
	level = 1;
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	raw();
	draw_maze(level);
	getmaxyx(stdscr, y, x);
	mvprintw(y/2, x/2, "@");
	refresh();
	getyx(stdscr, y, x);
	x--;
	move(y, x);
	refresh();
	getyx(stdscr, y, x);
	x--;
	while ((c = getch()) != 3)
	{
		switch(c)
		{
			case KEY_UP :
			{
				getyx(stdscr, y, x);
				y--;
				move(y, x);
				wall = inch();
				if(wall == '.')
				{
					getyx(stdscr, y, x);
					y++;
					move(y, x);
					refresh();
				}
				else 
					if(wall == ' ')
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
					}
				else
					if(wall == 'o')
					{
						clear();
						getmaxyx(stdscr, y, x);
						mvprintw(y/2, x/4, "Congratulations, you have completed level %i", level);
						level++;
						draw_maze(level);
					}
				break;
			}
			case KEY_DOWN :
			{
				getyx(stdscr, y, x);
				y++;
				move(y, x);
				wall = inch();
				if(wall == '.')
				{
					getyx(stdscr, y, x);
					y--;
					move(y, x);
					refresh();
				}
				if(wall == ' ')
				{
					y--;
					x--;
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
				}
				if(wall == 'o')
				{
					clear();
					getmaxyx(stdscr, y, x);
					mvprintw(y/2, x/4, "Congratulations, you have completed level %i", level);
					draw_maze(level);
					level++;
				}
			}
			case KEY_LEFT :
			{
				getyx(stdscr, y, x);
				x--;
				move(y, x);
				wall = inch();
				if(wall == '.')
				{
					getyx(stdscr, y, x);
					x++;
					move(y, x);
					refresh();
				}
				if(wall == ' ')
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
				}
				if(wall == 'o')
				{
					clear();
					getmaxyx(stdscr, y, x);
					mvprintw(y/2, x/4, "Congratulations, you have completed level %i", level);
					draw_maze(level);
					level++;
				}
				break;
			}
			case KEY_RIGHT :
			{
				getyx(stdscr, y, x);
				x++;
				move(y, x);
				wall = inch();
				if(wall == '.')
				{
					getyx(stdscr, y, x);
					x--;
					move(y, x);
					refresh();
				}
				if(wall == ' ')
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
				}
				if(wall == 'o')
				{
					clear();
					getmaxyx(stdscr, y, x);
					mvprintw(y/2, x/4, "Congratulations, you have completed level %i", level);
					draw_maze(level);
					level++;
				}
				break;
			}
			default:break;
		}
		refresh();
	}
	endwin();
	return 0;
}