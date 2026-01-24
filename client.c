/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 23:06:14 by lstarek           #+#    #+#             */
/*   Updated: 2026/01/19 23:26:53 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_message	g_message = {NULL, 0, 0, 0};

void	send_message(int num, siginfo_t *info, void *mask)
{
	(void)num;
	(void)info;
	(void)mask;
	if (num == SIGUSR2)
		exit(0);
	if (g_message.msg[g_message.byte] == 0 && g_message.bit >= 8)
	{
		return ;
	}
	if ((g_message.msg[g_message.byte] >> g_message.bit) & 1)
		kill(g_message.destination, SIGUSR1);
	else
		kill(g_message.destination, SIGUSR2);
	g_message.bit++;
	if (g_message.bit >= 8)
	{
		g_message.bit = 0;
		g_message.byte++;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	answer;

	if (ac != 3 || ft_atoi(av[1]) <= 0)
	{
		ft_printf("\nCORRECT USAGE:\n./client <server PID> <message>\n\n");
		return (0);
	}
	g_message.msg = av[2];
	answer.sa_sigaction = send_message;
	answer.sa_flags = SA_SIGINFO;
	sigemptyset(&answer.sa_mask);
	sigaction(SIGUSR1, &answer, NULL);
	sigaction(SIGUSR2, &answer, NULL);
	g_message.destination = ft_atoi(av[1]);
	send_message(1, NULL, NULL);
	while ((g_message.byte <= (sig_atomic_t)ft_strlen(av[2]))
		&& (g_message.bit < 8))
	{
		pause();
	}
	return (0);
}
