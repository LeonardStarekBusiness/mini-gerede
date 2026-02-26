/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:17:12 by lstarek           #+#    #+#             */
/*   Updated: 2026/01/18 15:18:06 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_message
{
	char			*msg;
	sig_atomic_t	byte;
	sig_atomic_t	bit;
	sig_atomic_t	destination;
}					t_message;

typedef struct s_octet
{
	sig_atomic_t	byte;
	sig_atomic_t	recieved;
}					t_octet;

int					ft_putnbr(int n);
size_t				ft_strlen(const char *str);
int					ft_atoi(const char *str);

#endif // MINITALK_H
