#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// ʵ��5.1
//void main()
//{
//	int a = 0, b = 0, c = 0;
//	scanf("%d%d%d", &a, &b, &c);
//	int tmp = max(a, b);
//	printf("%d", max(tmp, c));
//}
// 
// ʵ��5.2
//void main()
//{
//	int num;
//	printf("������һ����������");
//	scanf("%d", &num);
//	if (num % 2 == 0)
//		printf("%d��ż��", num);
//	else
//		printf("%d������", num);
//}
// 
// ʵ��5.3
//void main()
//{
//	int x = 0, y = 0;
//	printf("������һ����������");
//	scanf("%d", &x);
//	if (x < 1)
//	{
//		y = x;
//		printf("x=%3d,y=x=%d\n", x, y);
//	}
//	else if (x >= 1 && x < 12)
//	{
//		y = 3*x - 1;
//		printf("x=%3d,y=3x-1=%d\n", x, y);
//	}
//	else
//	{
//		y = 4 * x - 11;
//		printf("x=%3d,y=4x-11=%d\n", x, y);
//	}
//}
// 
// ʵ��5.4
//void main()
//{
//	int num;
//	printf("������һ����������");
//	scanf("%d", &num);
//	if (num % 5 == 0 && num % 7 == 0)
//		printf("yes");
//	else
//		printf("no");
//}
// 
// ʵ��5.5
//void main()
//{
//	char ch;
//	printf("�����룺");
//	scanf("%c", &ch);
//	if (ch > 64 && ch < 91)
//		ch += 32;
//	else if (ch > 96 && ch < 123)
//		ch -= 32;
//	else
//		ch++;
//	printf("%c", ch);
//}
// 
// ʵ��5.6
//void main()
//{
//	int a = 0, b = 0;
//	printf("�����룺");
//	scanf("%d%d", &a,&b);
//	int num = a * a + b * b;
//	if (num > 100)
//		printf("%d", num / 100);
//	else
//		printf("%d", a + b);
//}
// 
// ʵ��5.7
//int compare(int* a, int* b)
//{
//	return *b - *a;
//}
//void print_arr(int* arr, int length)
//{
//	for (int i = 0; i < length; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//void main()
//{
//	int arr[3]={0};
//	printf("�����룺");
//	scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), compare);
//	print_arr(arr, sizeof(arr) / sizeof(arr[0]));
//}
