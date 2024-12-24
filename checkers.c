/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:55:21 by mohabid           #+#    #+#             */
/*   Updated: 2024/12/22 12:55:24 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	checking_syntax(char *number)
{
	int	i;

	i = 0;
	if (ft_strlen(number) > 11)
		return (TRUE);
	if (!(number[i] == '+' || number[i] == '-' || (number[i] >= '0'
				&& number[i] <= '9')))
		return (TRUE);
	if ((number[i] == '+' || number[i] == '-') && !(number[i + 1] >= '0'
			&& number[i + 1] <= '9'))
		return (TRUE);
	i++;
	while (number[i])
	{
		if (number[i] < '0' || number[i] > '9')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_bool	check_dub(t_stack *stack, int num)
{
	t_stack	*ptr;

	ptr = stack;
	if (ptr == NULL)
		return (FALSE);
	while (ptr->next)
	{
		if (ptr->num == num)
			return (TRUE);
		ptr = ptr->next;
	}
	return (FALSE);
}

t_bool	is_sorted(t_stack *stack)
{
	t_stack	*ptr;

	ptr = stack;
	while (ptr->next)
	{
		if (ptr->num > ptr->next->num)
			return (FALSE);
		ptr = ptr->next;
	}
	return (TRUE);
}
