/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal <baal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 23:06:14 by lstarek           #+#    #+#             */
/*   Updated: 2026/03/03 20:15:07 by baal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_message	g_message = {NULL, 0, 0, 0};

void	send_message(int num)
{
	if (num == SIGUSR2)
		exit(0);
	if ((g_message.msg[g_message.byte] == 0) && (g_message.bit >= 8))
		return ;
	if (g_message.bit >= 8)
	{
		g_message.bit = 0;
		g_message.byte++;
	}
	if ((g_message.msg[g_message.byte] >> (g_message.bit++)) & 1)
	{
		if (kill(g_message.destination, SIGUSR1) == -1)
			exit(-1);
		return ;
	}
	else
	{
		if (kill(g_message.destination, SIGUSR2) == -1)
			exit(-1);
		return ;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	answer;

	if (ac != 3 || ft_atoi(av[1]) <= 0)
	{
		write(STDOUT_FILENO,
			"\nCORRECT USAGE:\n./client <server PID> <message>\n\n", 50);
		return (0);
	}
	g_message.msg = av[2];
	answer.sa_handler = send_message;
	answer.sa_flags = 0;
	sigemptyset(&answer.sa_mask);
	sigaction(SIGUSR1, &answer, NULL);
	sigaction(SIGUSR2, &answer, NULL);
	g_message.destination = ft_atoi(av[1]);
	send_message(1);
	while (1)
	{
		pause();
	}
	return (0);
}
