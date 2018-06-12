/*
** EPITECH PROJECT, 2018
** navy
** File description:
** Test for file.
*/

#include <unistd.h>
#include <criterion/criterion.h>
#include "my.h"
#include "navy.h"

Test(parse_arg, option)
{
	char *av[3] = {"test", "-azert", NULL};

	cr_assert_eq(parse_arg(2, av), ERROR);
	av[1] = "-hh";
	cr_assert_eq(parse_arg(2, av), ERROR);
	av[1] = "-";
	cr_assert_eq(parse_arg(2, av), ERROR);
	av[1] = "-h";
	cr_assert_eq(parse_arg(2, av), OPTION);
}

Test(parse_arg, ac)
{
	cr_assert_eq(parse_arg(1, NULL), ERROR);
	cr_assert_eq(parse_arg(4, NULL), ERROR);
}

Test(parse_arg, pid)
{
	char *av[4] = {"test", "sdfs", "file", NULL};

	cr_assert_eq(parse_arg(3, av), ERROR);
}

Test(parse_arg, file)
{
	char *av[4] = {"test", "12345", "file", NULL};

	cr_assert_eq(parse_arg(3, av), ERROR);
}

Test(parse_arg, no_errors)
{
	char *av[4] = {"test", "12345", "units", NULL};

	cr_assert_eq(parse_arg(3, av), CONTINUE);
}
