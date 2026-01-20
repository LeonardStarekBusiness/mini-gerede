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

#define _POSIX_C_SOURCE 200809L
#include "libft/libft.h"
#include <signal.h>
#include <spawn.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

typedef struct s_message
{
	char	*msg;
	size_t	byte;
	char	bit;
	int		destination;
}			t_message;

typedef struct s_octet
{
	char	byte;
	char	recieved;
}			t_octet;