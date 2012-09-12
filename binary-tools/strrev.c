#include <stdio.h>
#include "strrev.h"

void strrev(char in[])
{
	int i, j;
	i = 0;
	while (in[i] != '\0')
		++i;
	for(j = i; i >= 0; --i)
		putchar(in[i]);
}