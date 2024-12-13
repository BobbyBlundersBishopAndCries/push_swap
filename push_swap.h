/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:51:18 by mohabid           #+#    #+#             */
/*   Updated: 2024/12/13 03:08:01 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}				t_stack;

/* stack definition utils.c */
int		is_data_repeated(t_stack *stack, int value);
t_stack	*check_init(int ac, char **av);
char	*ft_strchr(char *s, int c);
/* functions_a.c */
void	swap_a(t_stack **a);
void	push_a(t_stack **dest, t_stack **src);
void	rotation_a(t_stack **a);
void	reverse_rotation_a(t_stack **a);
int		add_back(t_stack **a, int value);
/* functions_b.c */
void	swap_b(t_stack **a);
void	push_b(t_stack **dest, t_stack **src);
void	rotation_b(t_stack **a);
void	reverse_rotation_b(t_stack **a);
void	free_stack(t_stack **stack);
/* utils helper.c */
void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **stack1, t_stack **stack2);
void	rrr(t_stack **stack1, t_stack **stack2);
int		ft_lstsize(t_stack *stack);
t_stack	*ft_lstlast(t_stack *lst);
/* ft_split.c */
char	**ft_split(char *av, char c);
size_t	ft_strlen(char *s);
/* ft_string_fd.c */
int		costum_atoi(char *nptr);
int		ft_strcmp(char *s1, char *s2);
void	ft_putendl_fd(char *s, int fd);
/* ft_substr.c */
char	*ft_substr(char *s, unsigned int start, size_t len);
/* get_mid_index_value.c */
int		get_median(t_stack *a);
/* sort.c */
void	restore_rotations(t_stack **a, int ra_count);
t_stack	*highest(t_stack *a);
void	sort_three(t_stack **a);
void	partition_stack(t_stack **a, t_stack **b, int pivot);
/* s_algo.c*/
void	sort_stack(t_stack **a, t_stack **b);
int		is_stack_sorted(t_stack *stack);
/* main.c */
void	reverse_rotatation_no_log(t_stack **stack);
void	rotation_no_log(t_stack **stack);
void	swap_no_log(t_stack **stack);
int		main(int argc, char **argv);
#endif