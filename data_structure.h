#pragma once


enum Slime_State { GROWTH, ATTACK, ESCAPE, DEAD };

typedef struct NPC_Slime {
	// location
	int x, y;
	// gameplay attribute
	int hp, attackpoint;
	// use to control the slime
	enum Slime_State cur_state;
}Slime;

typedef struct Player_Hero {
	// location
	int x, y;
	// gameplay attribute
	int hp, attackpoint;
}Hero;
