#include <stdio.h>
#include <math.h>

int main (int argc, char const *argv[])
{
	int total, ptr, i = 0;
	char input[100];
	scanf("%s", input);
	while (input[i] != '\0')
	{
		total = 0;
		ptr = 0;
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
			}
		}
		printf("%i\n", total);
		input[0-100] = '\0';
		i = 0;
		scanf("%s", input);
	}
	return 0;
}