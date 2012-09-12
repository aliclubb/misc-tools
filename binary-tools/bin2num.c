#include <stdio.h>
#include <math.h>

int main (int argc, char const *argv[])
{
	int total = 0, ptr = 0, i = 0;
	char input[10];
	scanf("%s", input);
	while (input[i] != EOF)
		++i;
	while (i >= 0)
	{
		switch(input[i--])
		{
			case '1' : 
			{
				total += pow(2, ptr++);
				break;
			}
			case '0' : 
			{
				ptr++;
				break;
			}
			default : break;
		}
	}
	printf("%i\n", total);
	return 0;
}