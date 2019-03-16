#include<stdio.h>
#include"game_world.h"

int main()
{
	game_introduction();
	game_initialization();

	// 0-Game Over 
	// 1-Game On
	int game_state = 1;

	while(game_state){
		game_board_display();
		
		game_state = game_update();
		
		game_attribute_display();

		getchar();
		system("cls");
	}

	game_exit();

	return 0;
}
