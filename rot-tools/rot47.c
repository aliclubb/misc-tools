#include <stdio.h>

int main (c)
{
	while ((c = getchar()) != EOF)
		if(32 < c)
			if(c < 80)
				putchar(c + 47);
			else
				putchar(c - 47);
		else
			putchar(c);
	return 0;
}