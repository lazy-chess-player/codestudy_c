#include<stdio.h>
int main(){
	long long a, b;
	scanf("%ld%ld", &a, &b);
	printf("%ld", (b < 0 ? -1 : 1) * (a < 0 ? -a : a));
	return 0;
}