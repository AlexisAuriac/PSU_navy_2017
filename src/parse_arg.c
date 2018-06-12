/*
** EPITECH PROJECT, 2018
** navy
** File description:
** Parses arguments.
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include "my.h"
#include "struct.h"

void help(void)
{
	my_putstr("USAGE\n");
	my_putstr("\t./navy [first_player_pid] navy_positions\n");
	my_putstr("DESCRIPTION\n");
	my_putstr("\tfirst_player_pid: only for the 2nd player. ");
	my_putstr("pid of the first player.\n");
	my_putstr("\tnavy_positions: file representing the positions of the ");
	my_putstr("ships.\n");
}

error_t option(const char *arg)
{
	if (my_strcmp(arg, "-h") == 0) {
		help();
		return (OPTION);
	}
	else {
		my_putstr("Invalid option\n");
		return (ERROR);
	}
}

error_t error_1player(char **av, int *fd)
{
	*fd = open(av[1], O_RDONLY);
	if (*fd == -1) {
		my_putstr("The map doesn't exist or can't be opened\n");
		return (ERROR);
	}
	close(*fd);
	return (OK);
}

error_t error_2player(char **av, int *fd)
{
	if (!my_str_is(av[1], IS_NUM)) {
		my_putstr("You must give the pid of your opponent\n");
		return (ERROR);
	}
	*fd = open(av[2], O_RDONLY);
	if (*fd == -1) {
		my_putstr("The map doesn't exist or can't be opened\n");
		return (ERROR);
	}
	close(*fd);
	return (OK);
}

error_t parse_arg(int ac, char **av)
{
	int fd = -1;

	if (ac == 2) {
		if (av[1][0] == '-')
			return (option(av[1]));
		else
			return (error_1player(av, &fd));
	}
	else if (ac == 3)
		return (error_2player(av, &fd));
	my_putstr("Invalid number of arguments\n");
	return (ERROR);
}
