#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char vowel[] = "aeiouAEIOU";
bool isVowel(char ch)
{
    for (int i = 0; vowel[i]; i++)
    {
        if (vowel[i] == ch)
        {
            return true;
        }
    }
    return false;
}
char* reverseVowels(char* s)
{
    int len = strlen(s);
    int left = 0;
    int right = len - 1;
    while (right > left)
    {
        for (; right > 0 && !isVowel(s[right]); right--);
        for (; left < len && !isVowel(s[left]); left++);
        if (right > left)
        {
            char* tmp = s[right];
            s[right] = s[left];
            s[left] = tmp;
            left++;
            right--;
        }
    }
    return s;
}
void main()
{
	char arr[] = "sadwfsef";
	printf("%s", reverseVowels(arr));
}