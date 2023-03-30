#include <stdio.h>
int main()
{
	char c;
	while ((c = getchar()) != '\n')
	{
		if (c <= '9')
			printf("%c", c);
	}
	return 0;
}