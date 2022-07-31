#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "luhn.h"

int main(void)
{
	long int i;
	long int *s;
	long int amt;

	printf("Enter the amount you want: ");
	scanf("%ld", &amt);
	s = assignCardNum(amt);
	for (i = 0; i < amt; i++)
	{
		printf("%ld\t%ld generated as at %s %s\n", (i + 1), s[i], __TIME__, __DATE__);
	}
	return (0);
}
