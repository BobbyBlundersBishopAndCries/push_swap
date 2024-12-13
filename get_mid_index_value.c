/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mid_index_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 06:50:10 by mohabid           #+#    #+#             */
/*   Updated: 2024/12/13 03:54:43 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_stack_unique(t_stack *a)
{
	t_stack	*current;

	current = a;
	if (a == NULL)
		return (1);
	while (current != NULL)
	{
		if (is_data_repeated(a, current->data))
			return (0);
		current = current->next;
	}
	return (1);
}

static int	*put_stack_in_table(t_stack *a)
{
	int		*t;
	t_stack	*current;
	int		i;
	int		size;

	i = 0;
	size = ft_lstsize(a);
	if (size == 0)
		return (NULL);
	current = a;
	if (!is_stack_unique(a))
		return (NULL);
	t = (int *)malloc(size * sizeof(int));
	if (t == NULL)
		return (NULL);
	while (current != NULL)
	{
		t[i] = current->data;
		i++;
		current = current->next;
	}
	return (t);
}

static int	*sort_table(t_stack *a)
{
	int	*t;
	int	i;
	int	j;
	int	swap;

	i = 0;
	t = put_stack_in_table(a);
	if (t == NULL)
		return (NULL);
	while (i < ft_lstsize(a) - 1)
	{
		j = 0;
		while (j < ft_lstsize(a) - 1)
		{
			if (t[j] > t[j + 1])
			{
				swap = t[j + 1];
				t[j + 1] = t[j];
				t[j] = swap;
			}
			j++;
		}
		i++;
	}
	return (t);
}

int	get_median(t_stack *a)
{
	int	*t;
	int	mid;
	int	mid_value;

	if (a == NULL)
		return (INT_MIN);
	t = sort_table(a);
	if (t == NULL)
		return (INT_MIN);
	mid = ft_lstsize(a) / 2;
	mid_value = t[mid];
	free(t);
	return (mid_value);
}
