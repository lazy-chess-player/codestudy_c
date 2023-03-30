#include <stdio.h>
#include <math.h>
void flip (int n,int j,int *arr)
{
	if (n > 0)
	{
		int a=n/10;
		j++;
		flip(a,j,arr);
	}
	arr[j - 1] = (n % 10);
}
int isPalindrome(int x)
{
	int j = 0;
	int m = 0;
	int arr[20]={0};
	flip(x, j, arr);
	int y = 0;
	int l = 0;
	for (int i =0;arr[i] !=0; i++)
	{
		l = i;
	}
	for (int k = l; k >= 0; k--)
	{
		y += arr[k] * pow(10, l - k);
	}
	if (y == x)
		return 1;
	else
		return 0;
}
void main()
{
	int a =isPalindrome(1234321);
	printf("%d\n", a);
}