#include "luhn.h"
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
