#include "luhn.h"
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
