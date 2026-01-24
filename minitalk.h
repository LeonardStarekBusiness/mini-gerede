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
# define _POSIX_C_SOURCE 200809L
# include "libft/libft.h"
# include <signal.h>
# include <spawn.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_message
{
	char			*msg;
	sig_atomic_t	byte;
	sig_atomic_t	bit;
	sig_atomic_t	destination;
}			t_message;

typedef struct s_octet
{
	sig_atomic_t	byte;
	sig_atomic_t	recieved;
}			t_octet;

#endif
