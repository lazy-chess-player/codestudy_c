#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
unsigned int my_strlen(const char* string)
{
	assert(string!=NULL);
	unsigned int length = 0;
	while (*(string++))
	{
		length++;
	}
	return length;
}
void main()
{
	char* arr = "hellow w";
	printf("%d\n", my_strlen(arr));
}