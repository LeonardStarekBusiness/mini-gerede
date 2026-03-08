/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal <baal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 23:06:14 by lstarek           #+#    #+#             */
/*   Updated: 2026/03/08 21:00:22 by baal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static double g_byte_data;

void	send_bit(pid_t dest, int sig)
{
	if (kill(dest, sig) == -1)
		exit(-1);
}

void	destroy_interference(pid_t client1, pid_t client2)
{
	write(1, "\nInterference detected, client killed\n", 39);
	g_byte_data = 0;
	kill(client1, SIGUSR2);
	kill(client2, SIGUSR2);
	return ;
}

void	handler(int num, siginfo_t *info, void *mask)
{
	t_octet	g_octet;

	mask = NULL;
	ft_memcpy(&g_octet, &g_byte_data, 8);
	if ((g_octet.last_sender != info->si_pid) && g_octet.recieved)
		return (destroy_interference(info->si_pid, g_octet.last_sender));
	g_octet.byte |= ((num == SIGUSR1) << g_octet.recieved);
	if (g_octet.recieved >= 7)
	{
		if (!g_octet.byte)
			mask = &g_octet;
		write(STDOUT_FILENO, &g_octet.byte, 1);
		g_octet = (t_octet){0, 0, 0};
	}
	else
		g_octet.recieved++;
	g_octet.last_sender = info->si_pid;
	ft_memcpy(&g_byte_data, &g_octet, 8);
	if (!mask)
		send_bit(info->si_pid, SIGUSR1);
	else
	{
		write(1, "\0", 1);
		send_bit(info->si_pid, SIGUSR2);
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
