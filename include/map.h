/*
** EPITECH PROJECT, 2018
** navy
** File description:
** Header for the map.
*/

#ifndef MAP_H
#define MAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

static const char map_init[10][19] = {
	" |A B C D E F G H\n",
	"-+---------------\n",
	"1|. . . . . . . .\n",
	"2|. . . . . . . .\n",
	"3|. . . . . . . .\n",
	"4|. . . . . . . .\n",
	"5|. . . . . . . .\n",
	"6|. . . . . . . .\n",
	"7|. . . . . . . .\n",
	"8|. . . . . . . .\n"
};

typedef struct maps {
	char **map;
	char **enemy_map;
	char tmp[18];
	int **boat;
	int enemy_int;
	int your_int;
}maps_t;

#endif
