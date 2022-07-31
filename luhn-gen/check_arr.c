#include "luhn.h"
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
