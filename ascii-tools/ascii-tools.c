#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char const *argv[])
{
	int i, c;
	if(strcmp(argv[1], "-ascii") == 0)
	{
		/* Small character to ASCII number converter */
		while ((c = getchar()) != EOF)
			printf("%i ", c);
	}
	else if(strcmp(argv[1], "-char") == 0)
	{
		/* Small ASCII number to character converter */
		char str[1];
		while ((scanf("%s", str)) != EOF)
		{
			i = atoi(str);
			putchar(i);
		}
		putchar('\n');
	}
	return 0;
}