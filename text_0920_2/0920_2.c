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
	int temp;                   // 交换过渡

	while (left < right) {      // 两个指针相遇，代表字符反转结束
		temp = s[left];
		s[left] = s[right];
		s[right] = temp;
		left++;                 // 完成交换以后，两个指针记得移位
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