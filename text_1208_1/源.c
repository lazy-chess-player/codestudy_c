#include <stdio.h>
#include <stdbool.h>
bool squareIsWhite(char* coordinates)
{
	if ((coordinates[0] - 96) % 2 == 0)
	{
		if ((coordinates[1] - 48) % 2 == 0)
			return false;
		else
			return true;
	}
	else
	{
		if ((coordinates[1] - 48) % 2 == 0)
			return true;
		else
			return false;
	}
}
int main()
{
	char board[] = "a1";
	printf("%d", squareIsWhite(board));
	return 0;
}