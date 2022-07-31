#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int randnum;
	int i = 0;
	int guess;

	srand(time(NULL));
	randnum = rand() % 100;
	do{
		printf("Guess the number: ");
		scanf("%d", &guess);
		if (guess < randnum)
			printf("Try higher\n");
		if (guess > randnum)
			printf("Try lower\n");
		i++;
	} while (guess != randnum);
	printf("Gotten after %d guess(es)\n", i);
}
