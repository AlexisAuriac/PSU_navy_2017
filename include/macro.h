/*
** EPITECH PROJECT, 2017
** navy
** File description:
** Macros header file.
*/

#ifndef MACROS_H
#define MACROS_H

#include "struct.h"

#define UNUSED __attribute__((unused))

#define PARSE_ERR(error)			\
	switch (error) {			\
	case ERROR :				\
		return (84);			\
	case OPTION :				\
		return (0);			\
	default:				\
		break;				\
	}

#endif
