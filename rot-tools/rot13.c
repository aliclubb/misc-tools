#include <stdio.h>
#include <ctype.h>

int main(c)
{
	while((c = getchar()) != EOF)
		if(isalpha(c))
			if((c < 78) || (96 < c && c < 110))
				putchar(c + 13);
			else
				putchar(c - 13);
		else
			putchar(c);
	return 0;
}