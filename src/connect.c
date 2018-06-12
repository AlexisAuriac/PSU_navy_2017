/*
** EPITECH PROJECT, 2018
** navy
** File description:
** Connects both players.
*/

#include <unistd.h>
#include <signal.h>
#include "my.h"
#include "navy.h"
#include "connect.h"

void pid_handler(UNUSED int signum, siginfo_t *infos, UNUSED void *context)
{
	mssg = infos->si_pid;
}

pid_t connect_first(void)
{
	int time = 0;

	my_printf("my_pid: %d\n", getpid());
	my_putstr("waiting for enemy's connexion...\n\n");
	while (mssg == -1 && time != 20) {
		usleep(500000);
		++time;
	}
	if (time == 20) {
		my_puterr("too long connection time\n");
		return (-1);
	}
	kill(mssg, SIGUSR1);
	my_putstr("enemy connected\n\n");
	return (mssg);
}

pid_t connect_second(char *av_pid)
{
	pid_t enemy = my_getnbr(av_pid);
	int time = 0;

	my_printf("my_pid: %d\n", getpid());
	kill(enemy, SIGUSR1);
	while (mssg == -1 && time != 10) {
		usleep(50000);
		++time;
	}
	if (time != 10) {
		my_putstr("successfully connected\n\n");
		return (enemy);
	}
	else
		my_putstr("failed connection\n\n");
	return (-1);
}

pid_t connect(int player, char *av_pid)
{
	pid_t enemy = -1;
	struct sigaction act = {0};

	act.sa_sigaction = pid_handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	if (player == 1)
		enemy = connect_first();
	else
		enemy = connect_second(av_pid);
	signal(SIGUSR1, sigusr_handler);
	return (enemy);
}
