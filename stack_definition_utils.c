/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_definition_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:59:10 by mohabid           #+#    #+#             */
/*   Updated: 2024/12/10 11:31:24 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_data_repeated(t_stack *a, int value)
{
	t_stack	*current;

	current = a;
	while (current != NULL)
	{
		if (current->data == value)
			return (1);
		current = current->next;
	}
	return (0);
}

static void	handle_error(char **tokens)
{
	int	i;

	i = 0;
	ft_putendl_fd("Error", 2);
	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		tokens[i] = NULL;
		i++;
	}
	free(tokens);
}

static int	process_tokens(char **tokens, t_stack **a)
{
	int	j;
	int	value;

	j = 0;
	while (tokens[j] != NULL)
	{
		value = costum_atoi(tokens[j]);
		if ((value == INT_MIN && \
		ft_strcmp(tokens[j], "-2147483648") != 0)
			|| is_data_repeated(*a, value))
		{
			handle_error(tokens);
			return (0);
		}
		if (!add_back(a, value))
		{
			handle_error(tokens);
			return (0);
		}
		j++;
	}
	free(tokens);
	return (1);
}

t_stack	*check_init(int ac, char **av)
{
	t_stack	*a;
	int		i;
	char	**tokens;

	a = NULL;
	i = 1;
	while (i < ac)
	{
		tokens = ft_split(av[i], ' ');
		if (tokens == NULL)
		{
			free_stack(&a);
			return (NULL);
		}
		if (!process_tokens(tokens, &a))
		{
			free_stack(&a);
			return (NULL);
		}
		i++;
	}
	return (a);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!s)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
		len++;
	if (c == '\0')
		return ((char *)(s + len));
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
