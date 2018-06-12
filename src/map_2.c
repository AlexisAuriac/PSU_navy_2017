/*
** EPITECH PROJECT, 2018
** navy
** File description:
** second part of the map gestion
*/

#include "map.h"
#include "my.h"
#include "navy.h"

void print_game(maps_t *maps)
{
	write(1, "my positions:\n", 14);
	for (int i = 0 ; i < 10 ; ++i)
		write(1, maps->map[i], 18);
	write(1, "\nenemy's positions:\n", 20);
	for (int i = 0 ; i < 10 ; ++i)
		write(1, maps->enemy_map[i], 18);
	write(1, "\n", 1);
}

int map_generation(maps_t *maps)
{
	maps->map = malloc(sizeof(char *) * 10);
	maps->enemy_map = malloc(sizeof(char *) * 10);

	if (maps->map == NULL || maps->enemy_map == NULL)
		return (84);
	for (int i = 0; i < 10; ++i) {
		maps->map[i] = my_strdup(map_init[i]);
		maps->enemy_map[i] = my_strdup(map_init[i]);
		if (maps->map[i] == NULL || maps->enemy_map[i] == NULL)
			return (84);
	}
	return (0);
}

void fill_line_boat(maps_t *maps, int i)
{
	for (int y = 0; y < 7; ++y)
		switch (y) {
		case 0 : maps->boat[i][0] = maps->tmp[0] - 48;
			break;
		case 2 : maps->boat[i][2] = maps->tmp[2] - 64;
			break;
		case 3 : maps->boat[i][3] = maps->tmp[3] - 48;
			break;
		case 5 : maps->boat[i][5] = maps->tmp[5] - 64;
			break;
		case 6 : maps->boat[i][6] = maps->tmp[6] - 48;
			break;
		default : maps->boat[i][y] = maps->tmp[y];
		}
}

void free_map(maps_t *maps)
{
	for (int i = 0; i < 10; ++i) {
		if (i < 4)
			free(maps->boat[i]);
		free(maps->map[i]);
		free(maps->enemy_map[i]);
	}
	free(maps->map);
	free(maps->enemy_map);
	free(maps->boat);
	free(maps);
}
