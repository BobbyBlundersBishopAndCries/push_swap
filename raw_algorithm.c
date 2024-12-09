/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:02:00 by mohabid           #+#    #+#             */
/*   Updated: 2024/12/09 10:48:25 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    mid_point_algorithm(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	int		mid;
	t_stack	*current;
	int		size;
	int		bsize;
	t_stack	*bcurrent;
	int		bmid;
	int		highest;
	int		lowest;
	
	highest = highest_value(a);
	lowest = lowest_value(b);
	a = check_init(ac, av);
	b = NULL;
	current = a;
	size = ft_lstsize(a);
	if (is_stack_sorted_ascending(a))
		return ;
	if (size == 2)
	{
		if (current->data > current->next->data)
			swap_a(&a);
	}
	while (size > 2)
	{
		mid = get_mid_index_value(a);
		if (mid == INT_MIN)
			return ;
		while (current != NULL)
		{
			if (current->data < mid)
				push_b(&b, &a);
			else if (current->data >= mid && ft_lstlast(a)->data >= mid)
				rotation_a(&a);
			else if (current->data >= mid && ft_lstlast(a)->data < mid)
			{
				reverse_rotation_a(&a);
				push_b(&b, &a);
			}
			else if (current->data >= mid && current->next->data < mid)
			{
				swap_a(&a);
				push_b(&b, &a);
			}
			else if ((is_stack_sorted_ascending(current->next) && current->data == highest) && (is_stack_sorted_descending(b->next) && b->data == lowest))
			{
				rr(&a,&b);
				while (b != NULL)
				{
					push_a(&a, &b);
					b = b->next;
				}
			}
			else if ((is_sorted_until_last_ascending(current) && lowest == ft_lstlast(a))&& (is_sorted_until_last_descending(b) && b->data == highest))
			{
				rrr(&a, &b);
				while (b!= NULL)
				{
					push_a(&a, &b);
					b = b->next;
				}
			}
		}
	}
	bsize = ft_lstsize(b);
	bcurrent = b;
	if (is_stack_sorted_descending(b))
	{
		while (bcurrent != NULL)
		{
			push_a(&a, &b);
			bcurrent = bcurrent->next;
		}
	}
	if (bsize == 2)
	{
		if (bcurrent->data < bcurrent->next->data)
		{
			swap_b(&b);
			push_a(&a, &b);
			push_a(&a, &b);
		}
		else
		{
			push_a(&a, &b);
			push_a(&a, &b);
		}
	}
	while (bsize > 2)
	{
		bmid = get_mid_index_value(b);
		while (bcurrent != NULL)
		{
			if (bcurrent->data > bmid)
				push_a(&a, &b);
			else if (bcurrent->data <= bmid && ft_lstlast(b)->data > bmid)
			{
				reverse_rotation_b(&b);
				push_a(&a, &b);
			}
			else if (bcurrent->data <= bmid && ft_lstlast(b)->data <= bmid)
				rotation_b(&b);
			else if (bcurrent->data <= bmid && bcurrent->next->data > bmid)
			{
				swap_b(&b);
				push_a(&a, &b);
			}
		}
	}
}