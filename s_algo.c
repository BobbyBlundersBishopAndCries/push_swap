/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_algo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:08:38 by mohabid           #+#    #+#             */
/*   Updated: 2024/12/13 03:35:59 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_back_to_a(t_stack **a, t_stack **b)
{
	while (*b)
		push_a(a, b);
}

static void	quick_sort_stack(t_stack **a, t_stack **b)
{
	int	size;
    int pivot;

	size = ft_lstsize(*a);
	if (size == 3)
	{
		sort_three(a);
		return ;
	}
	pivot = get_median(*a);
	if (pivot == INT_MIN)
		return ;
	partition_stack(a, b, pivot);
	quick_sort_stack(a, b);
	push_back_to_a(a, b);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	if (a == NULL || *a == NULL || is_stack_sorted(*a))
		return ;
	quick_sort_stack(a, b);
}

int	is_stack_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}
