#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int guess_num = 77;
	int num = -1;
	while (guess_num!=num)
	{
		printf("��������µ�����:");
		scanf("%d", &num);
		if (num > guess_num)
			printf("�´���\n");
		else if (num < guess_num)
			printf("��С��\n");
		else
			printf("�¶���\n");
	}
	return 0;
}