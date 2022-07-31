#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

long int addDigits(long int num)
{
	long int sum = 0;

	while (num % 10 != 0 || num / 10 != 0)
	{
		sum += num % 10;
		num /= 10;
	}
	return (sum);
}
/*
long int countDigits(long int num)
{
	long int count = 1;

	while (num / 10 != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}*/
long int checkArr(long int *s, long int n, long int amt)
{
	long int i = 0;

	while (i < amt)
	{
		if (s[i] == n)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
long int assignControlNum(char *cutNum)
{
	long int n = atol(cutNum);
	long int i = 0;
	long int tmp;
	long int sum = 0;

	while (n / 10 != 0 || n % 10 != 0)
	{
		tmp = n % 10;
		if ((i % 2) == 0)
		{
			tmp *= 2;
		}
		tmp = addDigits(tmp);
		sum += tmp;
		n /= 10;
		i++;
	}
	sum = sum % 10;
	sum = 10 - sum;
	return (sum);
}
long int *assignCardNum(long int amt)
{
	long int j, i = 0;
	long int tmp;
	srand(time(NULL));
	long int r/* = rand()*/;
	char *str;
	char *str1;
	long int *res;

	res = malloc(amt * sizeof(long int));
	while (i < amt)
	{
		res[i] = 0;
		i++;
	}
	i = 0;
	str1 = malloc(1 * sizeof(char));
	for (j = 0; j < amt;)
	{
		str = malloc(4 * sizeof(char));
		str[0] = '5';
		str[1] = '1';
		str[2] = '9';
		str[3] = '9';
		i = 0;
		while (i < 11)
		{
			r = rand() % 10;
			str1[0] = '0' + r;
			strcat(str, str1);
			i++;
		}
		tmp = (atol(str) * 10) + assignControlNum(str);
		if ((checkArr(res, tmp, j) == 1))
		{
			res[j] = tmp;
			j++;
		}
		free(str);	
	}
	free(str1);
	return (res);
	free(res);
}
int main (int argc, char **argv)
{
if (argc == 2)
{
	long int i = 0;
	long int amt = atol(argv[1]);
	long int *arr;
	arr = malloc(amt * sizeof(long int));
	arr = assignCardNum(amt);
	while (i < amt)
	{
		printf("Card %ld is %ld\n", (i + 1), arr[i]);
		i++;
	}
	printf("Successfully generated %ld numbers\n", i);
	free(arr);
	return (0);
}
	return (-1);
}
