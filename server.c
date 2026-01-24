/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 23:06:14 by lstarek           #+#    #+#             */
/*   Updated: 2026/01/19 23:26:53 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_octet	g_octet = {0, 0};

int	ft_pow(int num1, int num2)
{
	int	orig;

	orig = num1;
	if (!num2)
		return (1);
	while (num2 > 1)
	{
		num1 *= orig;
		num2--;
	}
	return (num1);
}

void	handler(int num, siginfo_t *info, void *mask)
{
	int	end;

	(void)mask;
	end = 0;
	if (num == SIGUSR2)
		g_octet.byte |= (1 << g_octet.recieved);
	if (g_octet.recieved >= 7)
	{
		g_octet.byte = (unsigned char) ~g_octet.byte;
		if (!g_octet.byte)
			end = 1;
		write(STDOUT_FILENO, &g_octet.byte, 1);
		g_octet.byte = 0;
		g_octet.recieved = 0;
	}
	else
		g_octet.recieved++;
	if (!end)
		kill((int)info->si_pid, SIGUSR1);
	else
		kill((int)info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server ID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
