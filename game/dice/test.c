#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define _RED     "\x1b[31m"
#define _GREEN   "\x1b[32m"
#define _YELLOW  "\x1b[33m"
#define _BLUE    "\x1b[34m"
#define _MAGENTA "\x1b[35m"
#define _CYAN    "\x1b[36m"
#define I_COLOR_RESET   "\x1b[0m"
void printres(int n)
{
	if (n == 1)
		printf("-----------\n|         |\n|    *    |\n|         |\n-----------\n|   [1]   |\n-----------\n");
	if (n == 2)
		printf("-----------\n|      *  |\n|         |\n|  *      |\n-----------\n|   [2]   |\n-----------\n");
	if (n == 3)
		printf("-----------\n|      *  |\n|    *    |\n|  *      |\n-----------\n|   [3]   |\n-----------\n");
	if (n == 4)
		printf("-----------\n|  *   *  |\n|         |\n|  *   *  |\n-----------\n|   [4]   |\n-----------\n");
	if (n == 5)
		printf("-----------\n|  *   *  |\n|    *    |\n|  *   *  |\n-----------\n|   [5]   |\n-----------\n");
	if (n == 6)
		printf("-----------\n|  * * *  |\n|         |\n|  * * *  |\n-----------\n|   [6]   |\n-----------\n");
}
int *randomizer(void)
{
	int *n;

	n = malloc(2 * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < 2; i++)
	{
		n[i] = rand() % 6;
		n[i] += 1;
	}
	return (n);
}
void game(int player1, int player2)
{
	int *p1;
	int *p2;
	int pt1, pt2;
	char prompt;

	if (player1 != 0 && player2 != 0)
	{
		p1 = malloc(2 * sizeof(int));
		p2 = malloc(2 * sizeof(int));
		printf("+-+-+-+-+-+-+-+-+-+-+\n");
		printf(_GREEN "Game Started" _GREEN "\n");
		printf("+-+-+-+-+-+-+-+-+-+-+\n");
		printf(_YELLOW "PlayerOne %d : %d PlayerTwo" _YELLOW "\n", player1, player2);
		printf(_RED "Removing 10 points from each player" _RED "\n");
		printf("+-+-+-+-+-+-+-+-+-+-+\n");
		player1 -= 10;
		player2 -= 10;
		printf(_YELLOW "PlayerOne %d : %d PlayerTwo" _YELLOW "\n", player1, player2);
		printf(_RED "Rolling Dice...." _RED "\n");
		scanf("%c", &prompt);
		p1 = randomizer();
		pt1 = p1[0] + p1[1];
		printf(_BLUE "PlayerOne" _BLUE "\n");
		printres(p1[0]);
		printres(p1[1]);
		printf("PlayerOne Total: %d\n",pt1);
		scanf("%c", &prompt);
		printf(_RED "Rolling Dice.... " _RED "\n");
		scanf("%c", &prompt);
		p2 = randomizer();
		pt2 = p2[0] + p2[1];
		printf(_BLUE "PlayerTwo" _BLUE "\n");
		printres(p2[0]);
		printres(p2[1]);
		printf("PlayerTwo Total: %d\n",pt2);
		free(p1);
		free(p2);
		if (pt1 > pt2)
		{
			printf("PlayerOne rolled a total of %d\nPlayerTwo rolled a total of %d\n", pt1, pt2);
			printf(_CYAN "PlayerOne won the round!" _CYAN "\n");
			player1 += 20;
		}
		if (pt1 < pt2)
		{
			printf("PlayerOne rolled a total of %d\nPlayerTwo rolled a total of %d\n", pt1, pt2);
			printf(_CYAN "PlayerTwo won the round!" _CYAN "\n");
			player2 += 20;
		}
		if (pt1 == pt2)
		{
			printf("PlayerOne rolled a total of %d\nPlayerTwo rolled a total of %d\n", pt1, pt2);
			printf("Tie! Refunding players\n");
			player1 += 10;
			player2 += 10;
			printf("PlayerOne %d : %d PlayerTwo\n", player1, player2);
		}
		game(player1, player2);
	}
	else
	{
		if (player1 > player2)
		{
			printf("P1 won\n");
		}
		else
		{
			printf("P2 won\n");
		}
	}
	
}
int main(void)
{
	int player1 = 100;
	int player2 = 100;
	game(player1, player2);
	return (0);
}
