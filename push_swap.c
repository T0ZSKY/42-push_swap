/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:48:41 by tomlimon          #+#    #+#             */
/*   Updated: 2024/12/04 00:48:44 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = init_stack(argc - 1, argv);
	stack_b = init_stack(argc - 1, argv);
	if (!stack_a || !stack_b || !parse_args(argc, argv, stack_a))
	{
		ft_putstr_fd("Error\n", 1);
		free_stack(stack_a);
		free_stack(stack_b);
		return (1);
	}
	push_swap(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_is_sort_tab(stack_a->data, stack_a->size))
		return ;
	if (stack_a->size <= 3)
	{
		sort_simples_cases(stack_a);
		return ;
	}
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (stack_a->size > 3)
	{
		push_numbers_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (stack_b->size > 0)
	{
		push_numbers_to_a(stack_a, stack_b);
	}
	move_min_value_on_top(stack_a);
}

void	push_numbers_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	value;
	int	target_value;

	get_best_push(stack_a, stack_b, &value, &target_value);
	rotate_stacks_to_top(value, target_value, stack_a, stack_b);
	pb(stack_a, stack_b);
}

void	push_numbers_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	value;
	int	target_value;

	i = 0;
	value = stack_b->data[i];
	target_value = get_target_a_value(value, stack_a);
	while (stack_a->data[i] != target_value)
		i++;
	if (i < stack_a->size / 2)
		while (stack_a->data[0] != target_value)
			ra(stack_a);
	else
		while (stack_a->data[0] != target_value)
			rra(stack_a);
	pa(stack_a, stack_b);
}
