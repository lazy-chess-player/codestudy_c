#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool wordPattern(char* pattern, char* s)
{
    char* hash_map[26] = { NULL };
    const char target[2] = " ";
    int len = strlen(pattern);
    char* str_tmp = NULL;
    for (int i = 0; i < len; i++)
    {

        if (str_tmp == NULL)
        {
            str_tmp = strtok(s, target);
        }
        else
        {
            str_tmp = strtok(NULL, target);
            if (str_tmp == NULL)
            {
                return false;
            }
        }
        if (hash_map[pattern[i] - 'a'] == NULL)
        {
            hash_map[pattern[i] - 'a'] = str_tmp;
        }
        else
        {
            if (strcmp(hash_map[pattern[i] - 'a'], str_tmp) != 0)
            {
                return false;
            }
        }
    }
    str_tmp = strtok(NULL, target);
    if (str_tmp != NULL)
    {
        return false;
    }
    for (int i = 0; i < 26; i++)
    {
        if (hash_map[i] != NULL)
        {
            for (int j = i + 1; j < 26; j++)
            {
                if (hash_map[j] != NULL)
                {
                    if (strcmp(hash_map[i], hash_map[j]) == 0)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}