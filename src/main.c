/*
** EPITECH PROJECT, 2017
** navy
** File description:
** Main file.
*/

#include <unistd.h>
#include <signal.h>
#include "navy.h"
#include "map.h"

__attribute__((constructor)) void set_signals(void)
{
	signal(SIGUSR1, sigusr_handler);
	signal(SIGUSR2, sigusr_handler);
}

int main(int ac, char **av)
{
	pid_t enemy = -1;
	maps_t *maps = NULL;
	int win = 0;

	PARSE_ERR(parse_arg(ac, av));
	maps = map(ac, av);
	if (maps == NULL)
		return (84);
	enemy = connect((ac == 2) ? 1 : 2, av[1]);
	if (enemy < 0)
		return (84);
	win = navy(enemy, (ac == 2) ? 1 : 2, maps);
	free_map(maps);
	return (win);
}
