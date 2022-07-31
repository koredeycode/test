#include <stdio.h>
#include <stdarg.h>

double average(int num, ...)
{
	va_list arguments;
	double sum = 0;

	va_start(arguments, num);
	for (int x = 0; x < num; x++)
	{
		sum += va_arg(arguments, double);
	}
	va_end(arguments);
	return sum / num;
}

int sum (int n, ...)
{
	va_list args;
	int sum = 0;

	va_start(args, n);
	for (int x = 0; x < n; x++)
	{
		sum += va_arg(args, int);
	}
	va_end(args);
	return sum;
}
int func(int num)
{
	num = 4;
	return num;
}
int main(void)
{
	printf("%d\n", func(6));
}
