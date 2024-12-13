/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 03:41:37 by mohabid           #+#    #+#             */
/*   Updated: 2024/12/10 15:24:43 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **stack)
{
	t_stack	*temp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = (*stack);
		(*stack) = (*stack)->next;
		temp->next =(*stack)->next;
		(*stack)->next = temp; 
		ft_putendl_fd("sa", 1);
	}
}

void	push_a(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	if (src == NULL || *src == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
	ft_putendl_fd("pa", 1);
}

void	rotation_a(t_stack **stack)
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
	ft_putendl_fd("ra", 1);
}

void	reverse_rotation_a(t_stack **stack)
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
	ft_putendl_fd("rra", 1);
}

int	add_back(t_stack **a, int value)
{
	t_stack	*temp;
	t_stack	*current;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
		return (0);
	temp->data = value;
	if (*a == NULL)
	{
		*a = temp;
		temp->next = NULL;
		return (1);
	}
	current = *a;
	while (current->next != NULL)
		current = current->next;
	current->next = temp;
	temp->next = NULL;
	return (1);
}
