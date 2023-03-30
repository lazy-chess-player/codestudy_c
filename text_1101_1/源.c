#include <stdio.h>
char* addBinary(char* a, char* b)
{
	int carry = 0;
	int input = 0;
	int length = (strlen(a) > strlen(b) ? strlen(a) + 2 : strlen(b) + 2);
	char* result = (char*)malloc(sizeof(char) * length);
	result[length - 1] = '\0';
	for (int i = strlen(a) - 1, j = strlen(b) - 1, k = length - 2; (i >= 0) || (j >= 0); i--, j--, k--)
	{
		int sum = carry;
		sum += (i >= 0 ? a[i] - '0' : 0);
		sum += (j >= 0 ? b[j] - '0' : 0);
		carry = sum / 2;
		result[k] = '0' + sum % 2;
	}
	result[0] = carry + '0';
	if (carry == 0)
	{
		for (int i = 0; i < length - 1; i++)
			result[i] = result[i + 1];
	}
	return result;
}
void main()
{
	char a[] = "1101";
	char b[] = "1101";
	char* c = addBinary(a, b);
	printf("%s",c);
}