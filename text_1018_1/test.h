int ADD(int a, int b)
{
	return a + b;
}
int SUB(int a, int b)
{
	return a - b;
}
int MCL(int a, int b)
{
	return a * b;
}
int DIV(int a, int b)
{
	return a / b;
}
int (*counter[4])(int, int) = { ADD,SUB,MCL,DIV };
