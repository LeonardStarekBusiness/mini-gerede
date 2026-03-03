/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal <baal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 23:06:14 by lstarek           #+#    #+#             */
/*   Updated: 2026/03/03 20:45:58 by baal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static long double g_message_data;

void send_message(int num, siginfo_t *info, void *mask)
{
	(void)mask;
	t_message g_message;

	ft_memcpy(&g_message, &g_message_data, 10);
	if (num == SIGUSR2)
		exit(0);
	if ((*g_message.msg == 0) && (g_message.bit >= 8))
		return;
	if (g_message.bit >= 8)
	{
		g_message.bit = 0;
		g_message.msg++;
	}
	if ((*g_message.msg >> (g_message.bit++)) & 1)
	{
		ft_memcpy(&g_message_data, &g_message, 10);
		if (kill(info->si_pid, SIGUSR1) == -1)
			exit(-1);
		return;
	}
	else
	{
		ft_memcpy(&g_message_data, &g_message, 10);
		if (kill(info->si_pid, SIGUSR2) == -1)
			exit(-1);
		return;
	}
}

int main(int ac, char **av)
{
	struct sigaction answer;
	siginfo_t info;
	t_message g_message;

	if (ac != 3 || ft_atoi(av[1]) <= 0)
	{
		write(STDOUT_FILENO,
			  "\nCORRECT USAGE:\n./client <server PID> <message>\n\n", 50);
		return (0);
	}
	ft_memcpy(&g_message, &g_message_data, 10);
	g_message.msg = av[2];
	ft_memcpy(&g_message_data, &g_message, 10);
	answer.sa_sigaction = send_message;
	answer.sa_flags = SA_SIGINFO;
	sigemptyset(&answer.sa_mask);
	sigaction(SIGUSR1, &answer, NULL);
	sigaction(SIGUSR2, &answer, NULL);
	info.si_pid = ft_atoi(av[1]);
	send_message(1, &info, NULL);
	while (1)
		pause();
	return (0);
}
