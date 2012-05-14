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
		else if(c != 32)
			putchar(c + 13);
		else
			putchar(32);
	return 0;
}