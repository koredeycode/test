#include <stdio.h>
#include <stdlib.h>

/**
 * countDigits - the function count the number of digits in a given number
 * @num: the inputted number
 * Return: the number length, a long integer
 */
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
 * addDigits - the fuction add the digits in the inputted number
 * @num: the inputted number
 * Return: the sum of the numbers
 */
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
/**
 * validateCard - the function validate a card
 * @cardNum: the card number
 * Return: 1 if valid and 0 if otherwise
 */
long int validateCard(long int cardNum)
{
	long int controlNum = cardNum % 10;
	long int tmp, i = 1;
	long int sum = 0;

	cardNum /= 10;
	if (countDigits(cardNum) != 15)
	{
		return (0);
	}
	while (cardNum % 10 != 0 || cardNum / 10 != 0)
	{
		tmp = cardNum % 10;
		if (i % 2 == 1)
		{
			tmp *= 2;
		}
		tmp = addDigits(tmp);
		sum += tmp;
		cardNum /= 10;
		i++;
	}
	sum %= 10;
	sum = 10 - sum;
	if (sum == controlNum)
	{
		return (1);
	}
	return (0);
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
