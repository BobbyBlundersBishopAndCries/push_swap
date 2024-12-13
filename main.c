/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:38:38 by mohabid           #+#    #+#             */
/*   Updated: 2024/12/13 03:47:13 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_no_log(t_stack **stack)
{
	int	stockage;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		stockage = (*stack)->data;
		(*stack)->data = (*stack)->next->data;
		(*stack)->next->data = stockage;
	}
	return ;
}

void	rotation_no_log(t_stack **stack)
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
}

void	reverse_rotatation_no_log(t_stack **stack)
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
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = check_init(argc, argv);
	b = NULL;
	sort_stack(&a, &b);
	free_stack(&a);
	return (0);
}
