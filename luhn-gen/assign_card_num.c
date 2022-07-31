#include "luhn.h"

long int *assignCardNum(long int amt)
{
	long int j, i = 0;
	long int tmp;
	long int r;
	char *str;
	char *str1;
	long int *res;

	srand(time(NULL));
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
