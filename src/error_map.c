/*
** EPITECH PROJECT, 2018
** gestion of the error to the creation of the map
** File description:
** navy
*/

#include "my.h"
#include "navy.h"

int error_2_boat(maps_t *maps)
{
	int *boat = NULL;
	int check = 0;

	for (int i = 0; i < 4; ++i) {
		boat = maps->boat[i];
		if (boat[5] - boat[2] == boat[0] - 1 || !(boat[5] - boat[2])) {
			if (boat[6] - boat[3] == boat[0] - 1)
				++check;
			else if (boat[6] - boat[3] == 0)
				++check;
		}
	}
	if (check != 4)
		return (84);
	return (0);
}

int error_boat(maps_t *maps)
{
	for (int i = 0; i < 4; i++) {
		if (maps->boat[i][0] != i + 2)
			return (84);
		if (maps->boat[i][1] != ':' || maps->boat[i][4] != ':')
			return (84);
		for (int j = 2 ; j < 7 ; ++j) {
			if (j == 4)
				continue;
			else if (maps->boat[i][j] < 0 || maps->boat[i][j] > 9)
				return (84);
		}
	}
	return (error_2_boat(maps));
}
