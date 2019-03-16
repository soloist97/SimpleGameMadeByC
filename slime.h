#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"game_world.h"
#include"data_structure.h"
#include"hero.h"

enum { APi = 1, HPi = 1, ESCAPE_THRESHOLD=3};

void slime_growth(Slime* slime);
void slime_game_upate(Slime* slime, Hero* hero);