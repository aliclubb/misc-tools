/* Small character to ASCII number converter */
#include <stdio.h>
int main (c)
{
	while ((c = getchar()) != EOF)
		printf("%i ", c);
	return 0;
}