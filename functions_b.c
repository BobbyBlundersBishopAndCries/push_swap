/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:47:47 by mohabid           #+#    #+#             */
/*   Updated: 2024/12/10 15:25:40 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stack **stack)
{
	t_stack	*temp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = (*stack);
		(*stack) = (*stack)->next;
		temp->next =(*stack)->next;
		(*stack)->next = temp; 
		ft_putendl_fd("sb", 1);
	}
}

void	push_b(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	if (src == NULL || *src == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
	ft_putendl_fd("pb", 1);
}

void	rotation_b(t_stack **stack)
{
	t_stack	*first;
	t_stack	*current;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	current = first;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = first;
	*stack = first->next;
	first->next = NULL;
	ft_putendl_fd("rb", 1);
}

void	reverse_rotation_b(t_stack **stack)
{
	t_stack	*bf_last;
	t_stack	*current;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	current = *stack;
	while (current->next != NULL)
	{
		bf_last = current;
		current = current->next;
	}
	current->next = *stack;
	*stack = current;
	bf_last->next = NULL;
	ft_putendl_fd("rrb", 1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*next_node;
	t_stack	*current;

	current = *stack;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*stack = NULL;
}
