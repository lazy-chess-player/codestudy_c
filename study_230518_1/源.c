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
    printf("��������-��");
    scanf("%d", &num);
    printf("ȫ������������ = ");
    print_binary(num);
    printf("����λ = ");
    print_binary(num & 0x55555555);
    printf("ż��λ = ");
    print_binary(num & 0xAAAAAAAA);
    return 0;
}
