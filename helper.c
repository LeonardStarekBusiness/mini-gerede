/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal <baal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:21:20 by lstarek           #+#    #+#             */
/*   Updated: 2026/03/08 21:26:50 by baal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int abso(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int ft_putnbr(int n)
{
	char *map;
	int i;

	i = 0;
	map = "0123456789";
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else
	{
		if (abso(n) > 9)
		{
			i += ft_putnbr(n / 10);
			i += write(1, &map[abso(n % 10)], 1);
		}
		else
		{
			if (n < 0)
				i += write(1, "-", 1);
			i += write(1, &map[abso(n)], 1);
		}
	}
	return (i);
}

int		numlen(int n)
{
	int len;
	
	len = (n <= 0);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	nb;

	nb = n;
	len = numlen(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = 0;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[--len] = '0';
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
