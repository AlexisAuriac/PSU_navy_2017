/*
** EPITECH PROJECT, 2018
** navy
** File description:
** map's creation and management
*/

#include "map.h"
#include "my.h"
#include "navy.h"

int fill_colums_or_line(maps_t *maps, int x, char c, int *boat)
{
	if (c == 'c') {
		for (int y = boat[3] + 1 ; y < boat[6] + 2 ; ++y) {
			if (maps->map[y][x] != '.')
				return (84);
			maps->map[y][x] = boat[0] + '0';
		}
	}
	else if (c == 'l') {
		for (int y = boat[2] << 1 ; y <= boat[5] << 1 ; y += 2) {
			if (maps->map[x][y] != '.')
				return (84);
			maps->map[x][y] = boat[0] + '0';
		}
	}
	return (0);
}

int fill_map_boat(maps_t *maps)
{
	int *boat = NULL;

	for (int i = 0, x = 2 ; i < 4 ; ++i) {
		boat = maps->boat[i];
		if (boat[2] == boat[5]) {
			x = (boat[2] == 1) ? 2 : boat[2] << 1;
			if (fill_colums_or_line(maps, x, 'c', boat) == 84)
				return (84);
		} else {
			x = (boat[3] == 1) ? 2 : 1 + boat[3];
			if (fill_colums_or_line(maps, x, 'l', boat) == 84)
				return (84);
		}
	}
	return (0);
}

int fill_boat(maps_t *maps, int ac, char **av)
{
	char *files = (ac == 2) ? av[1] : av[2];
	int fd = open(files, O_RDONLY);
	int i = 0;

	if (fd == -1)
		return (84);
	i = read(fd, maps->tmp, 8);
	for (int x = 0; x < 4 && i != -1; ++x) {
		fill_line_boat(maps, x);
		i = read(fd, maps->tmp, 8);
	}
	close(fd);
	if (error_boat(maps) == 84)
		return (84);
	if (fill_map_boat(maps) == 84) {
		my_puterr("boat collision\n");
		return (84);
	}
	return (0);
}

int get_boat(maps_t *maps, int ac, char **av)
{
	maps->boat = malloc(sizeof(int *) * 4);
	if (maps->boat == NULL)
		return (84);
	for (int i = 0 ; i < 4 ; ++i) {
		maps->boat[i] = malloc(sizeof(int) * 7);
		if (maps->boat[i] == NULL) {
			while (i--)
				free(maps->boat[i]);
			free(maps->boat);
			return (84);
		}
	}
	if (fill_boat(maps, ac, av) == 84) {
		my_puterr("wrong position\n");
		return (84);
	}
	return (0);
}

maps_t *map(int ac, char **av)
{
	maps_t *maps = malloc(sizeof(maps_t));

	if (maps == NULL)
		return (NULL);
	maps->enemy_int = 14;
	maps->your_int = 14;
	if (map_generation(maps) == 84)
		return (NULL);
	if (get_boat(maps, ac, av) == 84)
		return (NULL);
	return (maps);
}
