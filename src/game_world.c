#include"game_world.h"

static Hero* hero = NULL;
static Slime* slime = NULL;

void game_introduction()
{
	printf("Once upon a time, there was a Slime in the Forest......\n");
	getchar();
	printf("It lived a very happy life, but......\n");
	getchar();
	printf("One day a Hero appeared(Yeh, that is you, bad guy!).......\n");
	getchar();
	printf("==================================\n");
	printf("How you control the Hero?\n");
	printf("WASD-Move, Q-Attack, E-Growth\n");
	printf("==================================\n");
	getchar();
	system("cls");
}


void game_initialization()
{
	if (hero != NULL) free(hero);
	if (slime != NULL) free(slime);

	hero = (Hero*)malloc(sizeof(Hero));
	slime = (Slime*)malloc(sizeof(Slime));

	// Determind the details of the slime
	// and put it on the board
	slime->hp = 5;
	slime->attackpoint = 1;
	slime->cur_state = GROWTH;
	srand((unsigned int)(time(NULL)));
	slime->x = rand() % (GAMEBOARDSIZE - 1) + 1;
	slime->y = rand() % (GAMEBOARDSIZE - 1) + 1;
	
	//Determind the details of the hero or heroine
	// and put he or she on the board
	hero->hp = 10;
	hero->attackpoint = 2;
	hero->x = 0;
	hero->y = 0;
}

void game_exit()
{
	if (hero != NULL) {
		free(hero);
		hero = NULL;
	}
	if (slime != NULL) {
		free(slime);
		slime = NULL;
	}
}

void game_board_display()
{

	printf("+MAP=====+\n");

	// Display the map
	int i = 0, j = 0;
	for (i = 0; i < GAMEBOARDSIZE; ++i) {
		for (j = 0; j < GAMEBOARDSIZE; ++j) {
			if (hero->x == i && hero->y == j) {
				printf("H  ");
			}
			else if (slime->x == i && slime->y == j) {
				printf("S  ");
			}
			else
				printf("#  ");
		}
		printf("\n");
	}
	printf("+========+\n");
}

void game_attribute_display()
{
	printf("________________________\n");
	printf("| Hero. | HP~%2d AP~%2d | \n", hero->hp, hero->attackpoint);
	printf("￣￣￣￣￣￣￣￣￣￣￣￣\n");
	printf("________________________\n");
	printf("| Slime | HP~%2d AP~%2d | \n", slime->hp, slime->attackpoint);
	printf("￣￣￣￣￣￣￣￣￣￣￣￣\n");
}

char game_input()
{
	char inputs[10];
	printf("Hero >>>>>>>");

	gets(inputs);

	return inputs[0];
}

void move_object(int *x, int *y, int dir)
{

	switch (dir) {
		case 0: //move up
			if (*x > 0) *x -= 1;
			break;
		case 1: //move down
			if (*x < GAMEBOARDSIZE-1) *x += 1;
			break;
		case 2: //move left
			if (*y > 0) *y -= 1;
			break;
		case 3://move right
			if (*y < GAMEBOARDSIZE - 1) *y += 1;
			break;
	}
}

int game_update()
{
	//check whether game is over
	if (slime->hp <= 0)
		return 0;
	if (hero->hp <= 0) {
		printf("You Lose....Even a slime is powerful than you 233333\n");
		return 0;
	}

	//update slime
	slime_game_upate(slime, hero);

	//check whether game is over
	if (slime->hp <= 0)
		return 0;
	if (hero->hp <= 0) {
		printf("You Lose....Even a slime is powerful than you 233333\n");
		return 0;
	}

	char input = game_input();

	//update hero
	hero_game_upate(slime, hero, input);

	return 1;
}
