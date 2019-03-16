#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"data_structure.h"
#include"slime.h"
#include"hero.h"

enum { GAMEBOARDSIZE = 4 };

void game_introduction();
void game_initialization();
void game_exit();
void game_board_display();
void game_attribute_display();
char game_input();
void move_object(int *x, int *y, int dir);
int game_update();
