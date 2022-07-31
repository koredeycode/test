#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *strcat(char *dest, const char *src);

int checkArr(char *s, long int n, int amt)
{
	int i = 0;

	while (i < amt)
	{
		if (atol(s[i]) == n)
		{
			return (0);
		}
	}
	return (1);
}
long int addDigits(long int num)
{
	long int sum = 0;

	while (num / 10 != 0)
	{
		sum += num / 10;
		num %= 10;
	}
	sum += num;
	return (sum);
}
long int assignControlNum(char *cutNum)
{
	long int n = atol(cutNum);
	int i = 0;

	while (n / 10 != 0 && n % 10 != 0)
	{

		i++;
	}
}
long int *assignCardNum(int amt)
{
	long int controlNum;
	long int j, i = 0;
	long int sum = 0;
	srand(time(NULL));
	long int r/* = rand()*/;
	char *str;
	char *str1;
	long int *res;

	res = malloc(amt * sizeof(long int));
	while (i < amt)
	{
		res[i] = 0;
	}
	str1 = malloc(1 * sizeof(char));
	for (j = 0; j < amt; j++)
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
		res[j] = atol(str);
		free(str);	
	}
	free(str1);
}
void main(void)
{
	int i;
	long int *s;

	s = assignCardNum();
	for (i = 0; i < 1000 i++)
	{
		printf("%d\t%ld\n", (i + 1); s[i]);
	}
}
long int countDigits(long int num)
{
	long int count = 1;

	while (num / 10 != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}
/**
 * main - entry point, to check the program
 * @argc: argument counts
 * @argv: the arguments
 */
void main(int argc, char **argv)
{
	if (argc > 1)
	{
		long int cardNo = atol(argv[1]);

		if (validateCard(cardNo) == 1)
		{
			printf("The card with number %ld is valid\n", cardNo);
		}
		else
		{
			printf("The card with number %ld is invalid\n", cardNo);
		}
	}
	else
	{
		printf("Usage: %s 'card no'\n", argv[0]);
	}
}
