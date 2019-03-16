#include"hero.h"

void hero_growth(Hero* hero)
{
	srand((unsigned int)(time(NULL)));

	if (rand() % 2 == 0) {
		hero->hp += HPi;
		printf("HP +%d\n", HPi);
	}
	else {
		hero->attackpoint += APi;
		printf("AP +%d\n", APi);
	}
}

void hero_game_upate(Slime* slime, Hero* hero, char input)
{
	switch (input) {
	case 'W'://move up
		move_object(&hero->x, &hero->y, 0);

		break;
	case 'S'://move down
		move_object(&hero->x, &hero->y, 1);

		break;
	case 'A'://move left
		move_object(&hero->x, &hero->y, 2);

		break;
	case 'D'://move right
		move_object(&hero->x, &hero->y, 3);

		break;
	case 'Q'://attack
		printf("Hero is ATTACKING >>>>>>");

		if (slime->x == hero->x&&slime->y == hero->y) {
			//hero attacks back slime
			slime->hp -= hero->attackpoint;
			printf("Hero attacks, Slime's HP -%d >>>>>>>", hero->attackpoint);
			//slime attacks hero
			hero->hp -= slime->attackpoint;
			printf("Slime bites back, Hero's HP -%d\n", slime->attackpoint/2);
		}
		else {
			printf("What? Hero just hit air?\n");
		}

		break;
	case 'E'://stand still
		printf("Hero rests on the block >>>>>>>");
		
		hero_growth(hero);

		break;
	}
}
