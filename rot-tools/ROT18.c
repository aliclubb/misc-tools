#include <stdio.h>

int main(c, t)
{
	while((c = getchar()) != 10)
		if((c >= 78 && c < 92) | (c >= 110))
		{
			t = 0;
			for(;(c >= 78 && c < 92) | (c >= 110);--c)
				++t;
			if(c > 92)
				putchar(96 + t);
			else
				putchar(64 + t);
		}
		else if(c != 32 && c > 60)
			putchar(c + 13);
		else if(c == 32)
			putchar(c);
		else if(c >= 53)
		{
			t = 0;
			for(;c >= 54;--c)
				++t;
			putchar(48 + t);
		}
		else
			putchar(c + 5);
	return 0;
}