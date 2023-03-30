#include <stdio.h>
void main() 
{
	int a;
	scanf_s("%d",&a);
	printf("%d",A(a));
}
int A(int x)
{
	if (x < 0)
		return 0;
	else if (x == 0)
		return 1;
	int input = x;
	int reverseNum = 0;
	while (x != 0)
	{
		int lastNum = x % 10;
		x /= 10;
		reverseNum = reverseNum * 10 + lastNum;
	}
	if (input == reverseNum)
		return 1;
	else
		return 0;
}