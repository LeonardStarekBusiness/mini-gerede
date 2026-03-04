/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal <baal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:21:20 by lstarek           #+#    #+#             */
/*   Updated: 2026/03/04 23:42:41 by baal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	nb;

	nb = n;
	len = (n <= 0);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
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