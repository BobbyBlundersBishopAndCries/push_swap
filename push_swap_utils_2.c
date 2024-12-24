/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:59:02 by mohabid           #+#    #+#             */
/*   Updated: 2024/12/22 13:06:24 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	highest_index(t_stack *stack)
{
	int	highest;

	highest = stack->index;
	while (stack)
	{
		if (stack->index > highest)
			highest = stack->index;
		stack = stack->next;
	}
	return (highest);
}

int	pos_finder(t_stack **stack, int pos)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index == pos)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	five_four(t_stack **stack_a)
{
	if (ft_lstsize(*stack_a) == 5)
		return (2);
	return (1);
}

int	n_chunks(int size)
{
	if (size > 5 && size < 100)
		return (3);
	else if (size == 100)
		return (5);
	return (9);
}
