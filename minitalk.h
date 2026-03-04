/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal <baal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:17:12 by lstarek           #+#    #+#             */
/*   Updated: 2026/03/04 23:42:34 by baal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define _POSIX_C_SOURCE 200809L
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef unsigned char	t_byte;

typedef struct s_message
{
	char		*msg;
	short		bit;
}			t_message;

typedef struct s_octet
{
	t_byte	byte;
	t_byte	recieved;
	pid_t	last_sender;
}			t_octet;

int			ft_putnbr(int n);
int			ft_atoi(const char *str);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_itoa(int n);

#endif // MINITALK_H
