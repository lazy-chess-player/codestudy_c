#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_binary(unsigned int num)
{
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);
        if (i % 2 == 0)
            printf(" ");
    }
    printf("\n");
}
int main()
{
    int num = 0;
    printf("输入数字-》");
    scanf("%d", &num);
    printf("全部二进制序列 = ");
    print_binary(num);
    printf("奇数位 = ");
    print_binary(num & 0x55555555);
    printf("偶数位 = ");
    print_binary(num & 0xAAAAAAAA);
    return 0;
}
