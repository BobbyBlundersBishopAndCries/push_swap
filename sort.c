/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:28:59 by mohabid           #+#    #+#             */
/*   Updated: 2024/12/13 04:09:11 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*highest(t_stack *a)
{
	t_stack	*highest;
	t_stack	*current;

	if (a == NULL)
		return (NULL);
	current = a;
	highest = a;
	while (current != NULL)
	{
		if (current-> data > highest->data)
			highest = current;
		current = current->next;
	}
	return (highest);
}

void	sort_three(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = highest(*a);
	if (*a == highest_node)
		rotation_a(a);
	if ((*a)->next == highest_node)
		reverse_rotation_a(a);
	if ((*a)->next->data < (*a)->data)
		swap_a(a);
}

void	partition_stack(t_stack **a, t_stack **b, int pivot)
{
	int	size;
	int	pb_count;
	int	ra_count;
	t_stack	*current;

	size = ft_lstsize(*a);
	pb_count = 0;
	ra_count = 0;
	current = *a;
	while (size)
	{
		if ((*a)->data < pivot)
		{
			//t_stack *tmp = current;
			push_b(b, a);
			pb_count++;
			size--;
		}
		else
		{
			rotation_a(a);
			ra_count++;
		}
	}
}