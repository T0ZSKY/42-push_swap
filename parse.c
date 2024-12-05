/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:48:47 by tomlimon          #+#    #+#             */
/*   Updated: 2024/12/04 12:05:08 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int capacity, char **argv)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	if (capacity == 1)
		stack->data = malloc(sizeof(int) * ft_count_words(argv[1], 32));
	else
		stack->data = malloc(sizeof(int) * capacity);
	if (!stack->data)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	stack->max = capacity;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		free(stack->data);
		free(stack);
	}
}

int	parse_args(int argc, char **argv, t_stack *stack_a)
{
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) == 0 && argv[i][0] != '0')
			return (0);
		if (ft_atoi(argv[i]) == 2147483647)
			return (0);
		num = ft_atoi(argv[i]);
		stack_a->data[stack_a->size++] = num;
		i++;
	}
	if (has_dubble(stack_a->data, stack_a->size))
		return (0);
	return (1);
}

void	sort_three(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	if (stack_a->size != 3)
		return ;
	a = stack_a->data[0];
	b = stack_a->data[1];
	c = stack_a->data[2];
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

void	sort_simples_cases(t_stack *stack_a)
{
	if (stack_a->size == 1)
		return ;
	if (stack_a->size == 2)
	{
		if (stack_a->data[0] > stack_a->data[1])
			ra(stack_a);
		return ;
	}
	if (stack_a->size == 3)
	{
		sort_three(stack_a);
		return ;
	}
}
