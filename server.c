/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal <baal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 23:06:14 by lstarek           #+#    #+#             */
/*   Updated: 2026/03/03 20:17:22 by baal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_octet g_octet = {0, 0};

void handler(int num, siginfo_t *info, void *mask)
{
	sig_atomic_t end;

	(void)mask;
	end = 0;
	if (num == SIGUSR1)
		g_octet.byte |= (1 << g_octet.recieved);
	if (g_octet.recieved >= 7)
	{
		end = !g_octet.byte;
		write(STDOUT_FILENO, &g_octet.byte, 1);
		g_octet = (t_octet){0, 0};
	}
	else
		g_octet.recieved++;
	if (!end)
	{
		if (kill((int)info->si_pid, SIGUSR1) == -1)
			exit(0);
	}
	else
	{
		write(1, "\0", 1);
		if (kill((int)info->si_pid, SIGUSR2) == -1)
			exit(0);
	}
}

int main(void)
{
	struct sigaction sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(STDOUT_FILENO, "Server PID: ", 13);
	ft_putnbr(getpid());
	write(STDOUT_FILENO, "\n", 1);
	while (1)
		pause();
	return (0);
}
