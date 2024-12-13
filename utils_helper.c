/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 06:38:20 by mohabid           #+#    #+#             */
/*   Updated: 2024/12/09 15:14:41 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	swap_no_log(a);
	swap_no_log(b);
	ft_putendl_fd("ss", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	rotation_no_log(a);
	rotation_no_log(b);
	ft_putendl_fd("rr", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotatation_no_log(a);
	reverse_rotatation_no_log(b);
	ft_putendl_fd("rrr", 1);
}

int	ft_lstsize(t_stack *stack)
{
	int		count;
	t_stack	*current;

	if (!stack)
		return (0);
	count = 0;
	current = stack;
	while (current != NULL)
	{
		count++;
		current = current -> next;
	}
	return (count);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*current;

	current = lst;
	if (!current)
		return (NULL);
	while (current -> next != NULL)
		current = current -> next;
	return (current);
}
