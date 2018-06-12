/*
** EPITECH PROJECT, 2018
** navy
** File description:
** Interactions with the map during the game.
*/

#include <stdbool.h>
#include "my.h"
#include "navy.h"
#include "map.h"

bool error_line(char *line)
{
	bool err = false;

	if (my_strlen(line) != 2)
		err = true;
	else if (line[0] < 'A' || line[0] > 'H')
		err = true;
	else if (line[1] < '1' || line[1] > '8')
		err = true;
	if (err)
		my_putstr("wrong position\n");
	return (err);
}

void feedback_attack(char *input, maps_t *maps, pid_t enemy)
{
	int col = input[0] - 'A' + 1;
	int line = input[1] - '0' + 1;

	if (receive_mssg(enemy)) {
		my_printf("%s: hit\n\n", input);
		maps->enemy_map[line][col * 2] = 'x';
		maps->enemy_int--;
	} else {
		my_printf("%s: missed\n\n", input);
		if (maps->enemy_map[line][col * 2] != 'x')
			maps->enemy_map[line][col * 2] = 'o';
	}
}

bool attack(pid_t enemy, maps_t *maps)
{
	char *line = NULL;

	do {
		if (line != NULL)
			free(line);
		my_putstr("attack: ");
		line = get_next_line(STDIN_FILENO);
		if (line == NULL) {
			send_mssg(enemy, 0);
			return (false);
		}
	} while (error_line(line));
	send_mssg(enemy, line[0] - 'A' + 1);
	send_mssg(enemy, line[1] - '0');
	feedback_attack(line, maps, enemy);
	free(line);
	return (true);
}

bool hit_boat(maps_t *maps, int col, int line)
{
	if (!in_str(maps->map[line + 1][col * 2], ".ox")) {
		maps->map[line + 1][col * 2] = 'x';
		return (true);
	}
	else if (maps->map[line + 1][col * 2] == '.')
		maps->map[line + 1][col * 2] = 'o';
	return (false);
}

bool defend(pid_t enemy, maps_t *maps)
{
	int col = 0;
	int line = 0;

	my_putstr("waiting for enemy's attack...\n");
	col = receive_mssg(enemy);
	if (col == 0)
		return (false);
	line = receive_mssg(enemy);
	if (hit_boat(maps, col, line)) {
		my_printf("%c%d: hit\n\n", col + 'A' - 1, line);
		maps->your_int--;
		send_mssg(enemy, 1);
	}
	else {
		my_printf("%c%d: missed\n\n", col + 'A' - 1, line);
		send_mssg(enemy, 0);
	}
	return (true);
}
