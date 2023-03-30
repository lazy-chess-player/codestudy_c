char** fizzBuzz(int n, int* returnSize)
{
    char** answer = (char**)malloc((sizeof(char*) * (n)));
    char* arr = (char*)malloc(sizeof(char) * n * 9);
    *returnSize = n; 
    for (int i = 0; i < n; i++)
    {
        answer[i] = &arr[9 * i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
            strcpy(answer[i - 1], "FizzBuzz");
        else if (i % 3 == 0)
            strcpy(answer[i - 1], "Fizz");
        else if (i % 5 == 0)
            strcpy(answer[i - 1], "Buzz");
        else
            sprintf(answer[i - 1], "%d", i);
        printf("answer[%d]=%s\n", i, answer[i - 1]);
    }
    return answer;
}