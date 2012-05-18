#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char const *argv[])
{
	if(argc == 1)
		printf("Usage: ascii-tools [inform] [outform]\nOptions:\nAny combination of the following:\n-ascii\n-char\n-html\n");
	else if((strcmp(argv[1], "-char") == 0) && (strcmp(argv[2], "-ascii") == 0))
	{
		/* Character to ASCII */
		int c;
		while ((c = getchar()) != EOF)
			printf("%i ", c);
	}
	else if((strcmp(argv[1], "-ascii") == 0) && (strcmp(argv[2], "-char") == 0))
	{
		/* ASCII to character */
		int i;
		char str[1];
		while ((scanf("%s", str)) != EOF)
		{
			i = atoi(str);
			putchar(i);
		}
	}
	else if((strcmp(argv[1], "-char") == 0) && (strcmp(argv[2], "-html") == 0))
	{
		/* Character to html code */
		int c;
		while ((c = getchar()) != EOF)
		{
			if(c >= 9 && c <= 255)
			{
				printf("&#");
			}
			printf("%i ", c);
		}
	}
	else if((strcmp(argv[1], "-ascii") == 0) && (strcmp(argv[2], "-html") == 0))
	{
		/* ASCII to html code */
		int i;
		char str[1];
		while (scanf("%s", str))
		{
			i = atoi(str);
			printf("&#%i ", i);
		}
	}
	return 0;
}