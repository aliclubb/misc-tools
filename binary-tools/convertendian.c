#include <stdio.h>
#include "strrev.h"

int main (int argc, char const *argv[])
{
	char input[100];
	scanf("%s", input);
	strrev(input);
	return 0;
}