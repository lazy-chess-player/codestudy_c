
#include <stdio.h>
int factorial(int n)
{
	if ( n > 1 )
		return n * factorial(n - 1);
	else
	    return 1;
}
void main()
{
	printf("%d\n", factorial(6));
}