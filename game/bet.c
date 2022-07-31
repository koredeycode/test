#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Print(char c)
{
	if (c == 'H')
	{
		putchar('\n');
printf("##     ##\n##     ##\n#########\n#########\n##     ##\n##     ##");
		putchar('\n');
	}
	if (c == 'T')
	{
		putchar('\n');
printf("##########\n##########\n   ##\n   ##\n   ##\n   ##");
		putchar('\n');
	}
}
void game(int balance)
{
	char arr[2] = {'H','T'};
	int bet;
	int randNum;
	char prompt;
	char guess;
	char res;
	char tmp;
	
	srand(time(NULL));
	printf("Welcome to the game\nPress 'C' to continue and 'E' to exit\n");
	scanf(" %c", &prompt);
	printf("\n==========\n");
	if (prompt != 'C' && prompt != 'E')
	{
		printf("\nIncorrect input\n");
		game(balance);
	}
	else if (prompt == 'C' && balance > 0)
	{
		printf("Balance: %d", balance);
		printf("\n==========\n");
		printf("\nEnter your bet: \n");
		scanf(" %d", &bet);
		if (bet > balance || bet == 0)
		{
			if (bet == 0)
			{
				printf("Balance can't be zero\n");
				printf("==========\n");
				game(balance);
			}
			printf("Balance not enough\n");
			printf("==========\n");
			game(balance);
		}
		balance -= bet;
		printf("==========\n");
		randNum = rand() % 2;
		for (int i = 0; i <= (rand() % 10); i++)
		{
			tmp = arr[0];
			arr[0] = arr[1];
			arr[1] = tmp;
		}
		res = arr[randNum];
		printf("\nInput your guess- 'H' for head 'T' for tail\nH or T?\n");
		scanf(" %c", &guess);
		printf("==========\n");
		if (guess == 'H' || guess == 'T')
		{
			Print(res);
			if ((guess == 'H' && res == 'H') || (guess == 'T' && res == 'T'))
			{
				printf("\nYou won\n");
				printf("==========");
				bet *= 2;
				balance += bet;
				game(balance);
			}
			else
			{
				printf("\nYou lost\n");
				printf("==========");
				game(balance);
			}
		}
		else
		{
			printf("\nIncorrect guess\n");
			printf("==========");
			game(balance);
		}

	}
	else if (prompt == 'C' && balance <= 0)
	{
		printf("\nInsufficient balance\n");
		printf("==========\n");
		exit(911);
	}
	else if (prompt == 'E')
	{
		printf("\nExited successfully\n");
		printf("==========\n");
	}
}

int main(void)
{
	int bal = 100;
	game(bal);
	return (0);
}
