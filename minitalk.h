/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal <baal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:17:12 by lstarek           #+#    #+#             */
/*   Updated: 2026/03/02 10:56:09 by baal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define _POSIX_C_SOURCE 200809L
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_message
{
	char			*msg;
	sig_atomic_t	byte;
	sig_atomic_t	bit;
	pid_t	destination;
}					t_message;

typedef struct s_octet
{
	unsigned char	byte;
	unsigned char	recieved;
}					t_octet;

int					ft_putnbr(int n);
size_t				ft_strlen(const char *str);
int					ft_atoi(const char *str);

#endif // MINITALK_H
