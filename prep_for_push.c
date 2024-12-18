/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_for_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:35:28 by mohabid           #+#    #+#             */
/*   Updated: 2024/12/18 03:16:27 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexation(t_stack *a)
{
	int	i;
	int size;
	
	i = 0;
	size = ft_lstsize(a);
	if (size == 0)
		return ;
	while (i < size)
	{
		if (i <= size / 2)
			a->above_median = 1;
		else
			a->above_median = 0;
		i++;
		a = a->next;
	}
}

void	prep_for_push_a(t_stack **a, t_stack *top)
{
	while (*a != top)
	{
		indexation(*a);
		if (top->above_median)
			rotation_a(a);
		else
			reverse_rotation_a(a);
	}
}

void	prep_for_push_b(t_stack **a, t_stack *cheapest)
{
	while (*a != cheapest)
	{
		indexation(*a);
		if (cheapest->above_median == 0)
			reverse_rotation_b(a);
		else
			rotation_b(a);
	}
}

int	is_sorted(t_stack *a)
{
	if (a == NULL)
		return (1);
	while (a)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}


void	sort_two_b(t_stack **a)
{
	if ((*a)->data < (*a)->next->data)
		swap_b(a);
}
