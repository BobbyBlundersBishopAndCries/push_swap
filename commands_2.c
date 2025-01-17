/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:55:31 by mohabid           #+#    #+#             */
/*   Updated: 2024/12/22 12:55:34 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	func_rev_rotate(t_stack **stack, int flag)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*prev;

	if (*stack && (*stack)->next)
	{
		last = ft_lstlast(*stack);
		temp = *stack;
		while (temp->next != last)
			temp = temp->next;
		prev = temp;
		temp = last;
		last = prev;
		last->next = NULL;
		temp->next = *stack;
		*stack = temp;
		if (flag == 1)
			ft_putstr_fd("rra\n", 1);
		else if (flag == 2)
			ft_putstr_fd("rrb\n", 1);
		else
			return ;
	}
}

void	func_rrr(t_stack **stack_a, t_stack **stack_b, int flag)
{
	func_rev_rotate(stack_a, 3);
	func_rev_rotate(stack_b, 3);
	if (flag == 1)
		ft_putstr_fd("rrr\n", 1);
	else
		return ;
}
