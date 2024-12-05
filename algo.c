/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:48:55 by tomlimon          #+#    #+#             */
/*   Updated: 2024/12/05 20:54:59 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target_b_value(int value, t_stack *stack_b)
{
	int	largest_smaller;
	int	max_value;
	int	current_value;
	int	index;

	if (!stack_b || stack_b->size <= 0)
		return (0);
	largest_smaller = INT_MIN;
	max_value = INT_MIN;
	index = 0;
	current_value = stack_b->data[0];
	while (index < stack_b->size)
	{
		current_value = stack_b->data[index];
		if (current_value > max_value)
			max_value = current_value;
		if (current_value < value && current_value > largest_smaller)
			largest_smaller = current_value;
		index++;
	}
	if (largest_smaller == INT_MIN)
		return (max_value);
	return (largest_smaller);
}

int	get_target_a_value(int value, t_stack *stack_a)
{
	int	smallest_greater;
	int	min_value;
	int	current_value;
	int	index;

	if (!stack_a || stack_a->size <= 0)
		return (0);
	smallest_greater = INT_MAX;
	min_value = INT_MAX;
	index = 0;
	while (index < stack_a->size)
	{
		current_value = stack_a->data[index];
		if (current_value < min_value)
			min_value = current_value;
		if (current_value > value && current_value < smallest_greater)
			smallest_greater = current_value;
		index++;
	}
	if (smallest_greater == INT_MAX)
		return (min_value);
	return (smallest_greater);
}

int	get_push_cost(int value, int target_value,
		t_stack *stack_a, t_stack *stack_b)
{
	int	rotations_a;
	int	reverse_rotations_a;
	int	rotations_b;
	int	reverse_rotations_b;

	rotations_a = get_rotations(stack_a, value);
	reverse_rotations_a = stack_a->size - rotations_a;
	rotations_b = get_rotations(stack_b, target_value);
	reverse_rotations_b = stack_b->size - rotations_b;
	return (get_min_cost(rotations_a, reverse_rotations_a)
		+ get_min_cost(rotations_b, reverse_rotations_b));
}

void	rotate_stacks_to_top(int value, int target_value, t_stack *stack_a,
		t_stack *stack_b)
{
	int	position_a;
	int	position_b;

	position_a = 0;
	position_b = 0;
	while (stack_a->data[position_a] != value)
		position_a++;
	while (stack_b->data[position_b] != target_value)
		position_b++;
	if (position_a < stack_a->size / 2)
		while (stack_a->data[0] != value)
			ra(stack_a);
	else
		while (stack_a->data[0] != value)
			rra(stack_a);
	if (position_b < stack_b->size / 2)
		while (stack_b->data[0] != target_value)
			rb(stack_b);
	else
		while (stack_b->data[0] != target_value)
			rrb(stack_b);
}

void	move_min_value_on_top(t_stack *stack_a)
{
	int	index;
	int	min_value;
	int	min_position;

	index = 0;
	min_position = 0;
	min_value = stack_a->data[0];
	while (index < stack_a->size)
	{
		if (min_value > stack_a->data[index])
		{
			min_value = stack_a->data[index];
			min_position = index;
		}
		index++;
	}
	if (min_position < stack_a->size / 2)
		while (stack_a->data[0] != min_value)
			ra(stack_a);
	else
		while (stack_a->data[0] != min_value)
			rra(stack_a);
}
