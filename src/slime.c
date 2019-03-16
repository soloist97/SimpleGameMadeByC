#include"slime.h"

void slime_growth(Slime* slime)
{
	srand((unsigned int)(time(NULL)));

	if (rand() % 2 ==  0) {
		slime->hp += HPi;
		printf("HP +%d >>>>>>", HPi);
	}
	else {
		slime->attackpoint += APi;
		printf("AP +%d >>>>>>", APi);
	}
}


void slime_game_upate(Slime* slime, Hero* hero) 
{
	switch (slime->cur_state){
		case GROWTH:
			printf("Slime is GROWING up >>>>>");
		
			//Increase HP or AP
			slime_growth(slime);

			if (slime->x == hero->x&&slime->y == hero->y) {
				if (slime->hp > ESCAPE_THRESHOLD) {
					printf("Hero detected! Slime is ready to ATTACK!\n");
					slime->cur_state = ATTACK;
				}
				else {
					printf("HP is toooo low! Slime is ready to ESCAPE!\n");
					slime->cur_state = ESCAPE;
				}
			}
			else {
				printf("What a nice place! Slime stays around.\n");
			}

			break;
		case ATTACK:
			printf("Slime is ATTACKING >>>>>>");

			if (slime->x == hero->x&&slime->y == hero->y) {
				//slime attacks hero
				hero->hp -= slime->attackpoint;
				printf("Slime bites, Hero HP's -%d >>>>>>", slime->attackpoint);
				//hero attacks back slime
				//slime->hp -= hero->attackpoint;
				//printf("Hero fights back, Slime HP's -%d >>>>>>>", hero->attackpoint/2);
			}
			else {
				printf("Lose target >>>>>>");
			}

			if (slime->x == hero->x&&slime->y == hero->y) {
				if (slime->hp > ESCAPE_THRESHOLD) {
					printf("Slime is ready to ATTACK again!\n");
					slime->cur_state = ATTACK;
				}
				else if(slime->hp > 0 && slime->hp<= ESCAPE_THRESHOLD){
					printf("HP is toooo low!");
					if (hero->hp > 0) {
						printf(" Slime is ready to ESCAPE!\n");
						slime->cur_state = ESCAPE;
					}
					else {
						printf("But, Slime wins at last!\n");
						slime->cur_state = GROWTH;
					}
				}
				else {
					printf("A great slime leaves us forever....... \n");
					slime->cur_state = DEAD;
				}
			}
			else {
				printf("What a Nice day! Slime stays around.\n");
				slime->cur_state = GROWTH;
			}

			break;
		case ESCAPE:
			printf("Slime is ESCAPING >>>>>>");

			srand((unsigned int)(time(NULL)));
			int dir = rand() % 4;
			switch (dir) {
				case 0: {printf("Slime tries to move up >>>>>>"); break; }
				case 1: {printf("Slime tries to move down >>>>>>"); break; }
				case 2: {printf("Slime tries to move left >>>>>>>"); break; }
				case 3: {printf("Slime tries to move right >>>>>>>"); break; }
			}
			move_object(&slime->x, &slime->y, dir);

			if (slime->x == hero->x&&slime->y == hero->y) {
				if (slime->hp > ESCAPE_THRESHOLD) {
					printf("Hero detected! Slime is ready to ATTACK!\n");
					slime->cur_state = ATTACK;
				}
				else{
					printf("HP is still toooo low! Slime keeps ESCAPING!\n");
					slime->cur_state = ESCAPE;
				}
			}
			else {
				printf("What a nice place! Slime stays around.\n");
				slime->cur_state = GROWTH;
			}

			break;
		case DEAD:
			break;
	}
}
