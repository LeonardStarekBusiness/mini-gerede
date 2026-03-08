/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal <baal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:21:20 by lstarek           #+#    #+#             */
/*   Updated: 2026/03/08 21:20:20 by baal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*csrc;
	unsigned char	*cdest;

	if (dest == NULL && src == NULL)
		return (NULL);
	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (cdest);
}

int ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (1)
	{
		if (s1[i] != s2[i] || !s1[i] || !s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
}

int ft_atoi(const char *str)
{
	int i;
	int minus_counter;
	int sum;

	i = 0;
	minus_counter = 0;
	sum = 0;
	while ((str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		minus_counter = (str[i] == '-');
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		sum = (sum * 10) + (str[i] - 48);
		i++;
	}
	if (minus_counter == 1)
		return (-sum);
	else
		return (sum);
}