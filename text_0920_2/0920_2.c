#include <stdio.h>
#include <string.h>
void reverseString(char* s, int sSize) {
	/*int right = sSize - 1;
	int left = 0;
	int tmp;
	while (left<right)
	{
		tmp = s[left];
		s[left] = s[right];
		s[right] = tmp;
		left++;
		right--;
	}*/
	int left = 0;
	int right = sSize - 1;
	int temp;                   // ��������

	while (left < right) {      // ����ָ�������������ַ���ת����
		temp = s[left];
		s[left] = s[right];
		s[right] = temp;
		left++;                 // ��ɽ����Ժ�����ָ��ǵ���λ
		right--;
	}
}
void main()
{
	char* arr = "hellow world";
	int strlength = strlen(arr);
	reverseString(arr, strlength);
	printf("%s ", arr);
}