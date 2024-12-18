/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:28:59 by mohabid           #+#    #+#             */
/*   Updated: 2024/12/18 03:16:19 by mohabid          ###   ########.fr       */
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

t_stack	*lowest(t_stack *b)
{
	t_stack	*lowest;
	t_stack	*current;

	if (b == NULL)
		return (NULL);
	current = b;
	lowest = b;
	indexation(b);
	while (current != NULL)
	{
		if (current-> data < lowest->data)
			lowest = current;
		current = current->next;
	}
	return (lowest);
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

void	sort_two_a(t_stack **a)
{
	if ((*a)->data > (*a)->next->data)
		swap_a(a);
}

void	sort_five(t_stack **a)
{
	t_stack	*lowest_node;
	t_stack **b;

	b = malloc(sizeof(t_stack*));
	if (!b)
		return ;
	*b = NULL;
	lowest_node = lowest(*a);
	prep_for_push_a(a, lowest_node);
	push_b(b, a);
	lowest_node = lowest(*a);
	prep_for_push_a(a,lowest_node);
	push_b(b, a);
	sort_three(a);
	sort_two_b(b);
	push_a(a, b);
	push_a(a, b);
	free(b);
}
