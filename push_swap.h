/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:39:23 by tomlimon          #+#    #+#             */
/*   Updated: 2024/12/05 20:56:17 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "./libft/libft.h"
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*data;
	int	size;
	int	max;
}	t_stack;

// --------------------------moove------------------------ //

void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rrb(t_stack *stack_b);
void	rra(t_stack *stack_a);
void	sa(t_stack *stack_a);
void	ft_swap(int *a, int *b);

// --------------------------utils------------------------ //

int		ft_count_words(const char *s, char c);
void	ft_putstr_fd(char *s, int fd);

// --------------------------verif------------------------ //

t_stack	*init_stack(int capacity, char **argv);
int		has_dubble(int *array, int size);
int		get_min_cost(int rotations, int reverse_rotations);

// --------------------------algo------------------------ //

void	push_swap(t_stack *stack_a, t_stack *stack_b);
void	sort_simples_cases(t_stack *stack_a);
void	push_numbers_to_b(t_stack *stack_a, t_stack *stack_b);
void	push_numbers_to_a(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack_a);
void	move_min_value_on_top(t_stack *stack_a);
void	get_best_push(t_stack *stack_a, t_stack *stack_b, int *best_value,
			int *best_target_value);
void	rotate_stacks_to_top(int value, int target_value, t_stack *stack_a,
			t_stack *stack_b);
int		get_target_a_value(int value, t_stack *stack_a);
int		get_target_b_value(int value, t_stack *stack_b);
int		get_rotations(t_stack *stack, int value);
int		get_push_cost(int value, int target_value,
			t_stack *stack_a, t_stack *stack_b);

// --------------------------utils------------------------ //

int		parse_args(int argc, char **argv, t_stack *stack_a);
void	free_stack(t_stack *stack);
int		ft_is_sort_tab(int *tab, int size);
void	ft_free_split(char **split);

#endif
