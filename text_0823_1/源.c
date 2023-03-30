#include <stdio.h>
int Fibonacci (int n)
{
	if (n > 2)
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	else
		return 1;
}
void main()
{
	printf("%d\n", Fibonacci(4));
}