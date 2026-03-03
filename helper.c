/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baal <baal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:21:20 by lstarek           #+#    #+#             */
/*   Updated: 2026/03/03 20:13:39 by baal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	abso(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	is_it_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	ft_putnbr(int n)
{
	char	*map;
	int		i;

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

int	ft_atoi(const char *str)
{
	int	i;
	int	minus_counter;
	int	sum;

	i = 0;
	minus_counter = 0;
	sum = 0;
	while (is_it_space(str[i]))
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

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n] != 0)
	{
		n++;
	}
	return (n);
}
