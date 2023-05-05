#include <stdio.h>
#include <memory.h>
#include <malloc.h>

int main()
{
	char str1[] = "abcdef";
	char str2[] = "ghijkl";
	printf("字符数组1：%s\n字符数组2：%s\n", str1, str2);
	char* temp = (char*)malloc(sizeof(str1));
	memcpy(temp, str1, sizeof(str1));
	memcpy(str1, str2, sizeof(str1));
	memcpy(str2, temp, sizeof(str1));
	if (temp == NULL)
		return;
	free(temp);
	printf("改变后：\n字符数组1：%s\n字符数组2：%s", str1, str2);
	return 0;
}