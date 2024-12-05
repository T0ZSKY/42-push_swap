/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:47:39 by tomlimon          #+#    #+#             */
/*   Updated: 2024/12/04 00:47:39 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_dubble(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_rotations(t_stack *stack, int value)
{
	int	index;

	index = 0;
	while (stack->data[index] != value)
		index++;
	return (index);
}

int	get_min_cost(int rotations, int reverse_rotations)
{
	if (rotations <= reverse_rotations)
		return (rotations);
	else
		return (reverse_rotations);
}

void	get_best_push(t_stack *stack_a, t_stack *stack_b,
		int *optimal_value, int *optimal_target_value)
{
	int	i;
	int	push_cost;
	int	min_push_cost;

	i = 0;
	*optimal_value = stack_a->data[i];
	*optimal_target_value = get_target_b_value(*optimal_value, stack_b);
	push_cost = get_push_cost(*optimal_value, *optimal_target_value,
			stack_a, stack_b);
	min_push_cost = push_cost;
	while (i < stack_a->size)
	{
		push_cost = get_push_cost(stack_a->data[i],
				get_target_b_value(stack_a->data[i],
					stack_b), stack_a, stack_b);
		if (push_cost < min_push_cost)
		{
			min_push_cost = push_cost;
			*optimal_value = stack_a->data[i];
			*optimal_target_value = get_target_b_value(*optimal_value, stack_b);
		}
		i++;
	}
}

int	ft_is_sort_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
