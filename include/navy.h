/*
** EPITECH PROJECT, 2017
** navy
** File description:
** Contains the prototypes of the project's functions.
*/

#ifndef NAVY_H
#define NAVY_H

#include <signal.h>
#include <stdbool.h>
#include "const.h"
#include "struct.h"
#include "macro.h"
#include "map.h"

//parse_arg.c
error_t parse_arg(int ac, char **av);

//connect.c
void pid_handler(UNUSED int signum, siginfo_t *infos, UNUSED void *context);
pid_t connect_first(void);
pid_t connect_second(char *av_pid);
pid_t connect(int player, char *av_pid);

//signal.c
void send_mssg(pid_t receiver, int nb);
int receive_mssg(pid_t sender);
void sigusr_handler(int signum);

//navy.c
bool play_turn(pid_t enemy, int player, maps_t *maps);
int navy(pid_t enemy, int player, maps_t *maps);

//map_2.c
void print_game(maps_t *maps);
int map_generation(maps_t *maps);
void fill_line_boat(maps_t *maps, int i);
int error_2_boat(maps_t *maps);
void free_map(maps_t *maps);

//map.c
int fill_map_boat(maps_t *maps);
int fill_boat(maps_t *maps, int ac, char **av);
int get_boat(maps_t *maps, int ac, char **av);
maps_t *map(int ac, char **av);
int fill_colums_or_line(maps_t *maps, int x, char c, int *boat);

//error_map.c
int error_2_boat(maps_t *maps);
int error_boat(maps_t *maps);

//game.c
bool error_line(char *line);
void feedback_attack(char *input, maps_t *maps, pid_t enemy);
bool attack(pid_t enemy, maps_t *maps);
bool hit_boat(maps_t *maps, int col, int line);
bool defend(pid_t enemy, maps_t *maps);

#endif
