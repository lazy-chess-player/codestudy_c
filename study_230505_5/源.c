#include <stdio.h>
#include <memory.h>
#include <malloc.h>

int main()
{
	char str1[] = "abcdef";
	char str2[] = "ghijkl";
	printf("�ַ�����1��%s\n�ַ�����2��%s\n", str1, str2);
	char* temp = (char*)malloc(sizeof(str1));
	memcpy(temp, str1, sizeof(str1));
	memcpy(str1, str2, sizeof(str1));
	memcpy(str2, temp, sizeof(str1));
	if (temp == NULL)
		return;
	free(temp);
	printf("�ı��\n�ַ�����1��%s\n�ַ�����2��%s", str1, str2);
	return 0;
}