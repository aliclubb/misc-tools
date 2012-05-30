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
			if(c < 48 || c > 58)
				putchar(c);
			else
				if((c > 32 && c < 53))
					putchar(c + 5);
				else
					putchar(c - 5);
	return 0;
}