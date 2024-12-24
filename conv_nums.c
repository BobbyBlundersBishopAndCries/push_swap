/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_nums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:56:09 by mohabid           #+#    #+#             */
/*   Updated: 2024/12/22 12:56:11 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

long	ft_atoi(const char *nptr)
{
	int			x;
	int			sign;
	long int	number;

	x = 0;
	sign = 1;
	number = 0;
	if (nptr[x] == '+' || nptr[x] == '-')
	{
		if (nptr[x++] == '-')
			sign *= -1;
	}
	while (nptr[x] >= '0' && nptr[x] <= '9')
	{
		number = number * 10 + (nptr[x] - 48);
		x++;
	}
	return (number * sign);
}
