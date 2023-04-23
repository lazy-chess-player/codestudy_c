#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int guess_num = 77;
	int num = -1;
	while (guess_num!=num)
	{
		printf("请输入你猜的数字:");
		scanf("%d", &num);
		if (num > guess_num)
			printf("猜大了\n");
		else if (num < guess_num)
			printf("猜小了\n");
		else
			printf("猜对了\n");
	}
	return 0;
}