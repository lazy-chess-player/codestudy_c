#include<stdio.h>
int main()
{
	int x, y;
	char ch1, ch2, ch3;
	scanf_s("%d,%d", &x, &y);
	getchar();                           //得到scanf语句输入的回车符
	printf("x=%d,y=%d\n", x, y);
	scanf_s("%c,%c,%c", &ch1, &ch2, &ch3);
	printf("ch1=%c,ch2=%c,ch3=%c\n", ch1, ch2, ch3);
	return 0;
}