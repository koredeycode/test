#include <stdio.h>
#include <stdarg.h>

int checker(char *chr)
{
	int i = 0;
	int count = 0;

	while (chr[i] != '\0')
	{
		if (chr[i] == '%' && chr[i - 1] != '\\')
		{
			count++;
		}
	}
	return (count);
}
int _printf(/*const*/char *fmt, ...)
{
	int num = checker(fmt);

	return num;
}

int main(void)
{
	printf("%d\n", _printf("this %d"));
	return (0);
}
