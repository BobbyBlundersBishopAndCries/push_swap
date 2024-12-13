/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 05:15:05 by mohabid           #+#    #+#             */
/*   Updated: 2024/12/10 10:27:47 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

static int	is_digit(char d)
{
	return (d >= '0' && d <= '9');
}

static int	parse_sign_and_whitespace(char *nptr, int *index)
{
	int	sign;
	int	i;

	sign = 1;
	i = *index;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	*index = i;
	return (sign);
}

int	costum_atoi(char *nptr)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	result = 0;
	sign = parse_sign_and_whitespace(nptr, &i);
	while (is_digit(nptr[i]))
	{
		if (result > (INT_MAX - (nptr[i] - '0')) / 10)
			return (INT_MIN);
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	if (i == 0 || (nptr[i] != '\0' && !is_digit(nptr[i])))
		return (INT_MIN);
	return (result * sign);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
