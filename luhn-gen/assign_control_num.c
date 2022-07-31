#include "luhn.h"

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
