/* Small ASCII number to character converter */
#include <stdio.h>
#include <stdlib.h>
int main (i)
{
	char str[1];
	while ((scanf("%s", str)) != EOF)
	{
		i = atoi(str);
		putchar(i);
	}
	putchar('\n');
	return 0;
}