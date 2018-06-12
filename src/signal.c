/*
** EPITECH PROJECT, 2018
** navy
** File description:
** Connects to the oppponent.
*/

#include <unistd.h>
#include <signal.h>
#include "my.h"
#include "navy.h"
#include "connect.h"

void send_mssg(pid_t receiver, int nb)
{
	for (int i = 0 ; i < 4 ; ++i) {
		mssg = -1;
		while (mssg == -1) {
			if (nb & 1)
				kill(receiver, SIGUSR1);
			else
				kill(receiver, SIGUSR2);
			usleep(1000);
		}
		nb >>= 1;
	}
}

int receive_mssg(pid_t sender)
{
	int nb = 0;
	int pow = 1;

	for (int i = 0 ; i < 4 ; ++i, pow <<= 1) {
		pause();
		if (mssg)
			nb |= pow;
		kill(sender, SIGUSR1);
	}
	return (nb);
}

void sigusr_handler(int signum)
{
	if (signum == SIGUSR1)
		mssg = 1;
	else if (signum == SIGUSR2)
		mssg = 0;
}
