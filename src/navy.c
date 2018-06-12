/*
** EPITECH PROJECT, 2018
** navy
** File description:
** Main game loop.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"
#include "navy.h"

bool play_turn(pid_t enemy, int player, maps_t *maps)
{
	if ((player == 1) ? !attack(enemy, maps) : !defend(enemy, maps))
		return (false);
	else if (!maps->your_int)
		return (true);
	else if ((player == 1) ? !defend(enemy, maps) : !attack(enemy, maps))
		return (false);
	return (true);
}

int navy(pid_t enemy, int player, maps_t *maps)
{
	print_game(maps);
	while (maps->enemy_int != 0 && maps->your_int != 0) {
		if (player == 1) {
			if (!play_turn(enemy, player, maps))
				break;
		} else {
			if (!play_turn(enemy, player, maps))
				break;
		}
		print_game(maps);
	}
	if (maps->your_int == 0) {
		my_putstr("Enemy won\n");
		return (1);
	}
	else if (maps->enemy_int == 0)
		my_putstr("I won\n");
	return (0);
}
