#include <stdio.h>
#include <string.h>
int numDifferentIntegers(char* word)
{
    int i = 0;
    int tmp[60] = { 0 };
    int count = 0;
    while (word[i])
    {
         int s = 0;
        while (word[i] >= 'a' && word[i] <= 'z')
            i++;
        if (word[i] == '\0')
            break;
        while (word[i] >= '0' && word[i] <= '9')
        {
            s = s * 10 + word[i] - 48;
            s %= 100000;
            i++;
        }
        int j = 0;
        for (; j < count; j++)
        {
            if (tmp[j] == s)
                break;
        }
        if (j >= count)
        {
            tmp[count] = s;
            count++;
        }
    }
    return count;
}
int main()
{
	char str[] = "a123bc34d8ef34";
	printf("%d", numDifferentIntegers(str));
	return 0;
}