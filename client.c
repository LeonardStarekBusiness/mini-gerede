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

t_message	message = {NULL, 0, 0, 0};

void	send_message(int num, siginfo_t *info, void *mask)
{
	(void)num;(void)info;(void)mask;
	if ((message.msg[message.byte]>>message.bit)&1)
		kill(message.destination, SIGUSR1);
	else
		kill(message.destination, SIGUSR2);
	message.bit++;
	if (message.bit >= 8)
	{
		message.bit = 0;
		message.byte++;
	}
}

int main(int ac, char **av)
{
	struct sigaction answer;

	message.msg = av[2];
    answer.sa_sigaction = send_message;
    answer.sa_flags = SA_SIGINFO;
    sigemptyset(&answer.sa_mask);
    sigaction(SIGUSR1, &answer, NULL);
	if (ac != 3 || ft_atoi(av[1]) <= 0)
	{
		ft_printf("\nCORRECT USAGE:\n./client <server PID> <message>\n\n");
		return (0);
	}
	message.destination = ft_atoi(av[1]);
	send_message(1, NULL, NULL);
	while ((message.byte <= ft_strlen(av[2])) && (message.bit < 8))
	{
		pause();
	}
}
