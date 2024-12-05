/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:48:23 by tomlimon          #+#    #+#             */
/*   Updated: 2024/12/04 00:48:28 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	ft_putstr_fd("pa\n", 1);
	i = stack_a->size;
	if (stack_b->size == 0)
		return ;
	while (i > 0)
	{
		stack_a->data[i] = stack_a->data[i - 1];
		i--;
	}
	stack_a->data[0] = stack_b->data[0];
	stack_a->size++;
	stack_b->size--;
	while (i < stack_b->size)
	{
		stack_b->data[i] = stack_b->data[i + 1];
		i++;
	}
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	ft_putstr_fd("pb\n", 1);
	i = stack_b->size;
	if (stack_a->size == 0)
		return ;
	while (i > 0)
	{
		stack_b->data[i] = stack_b->data[i - 1];
		i--;
	}
	stack_b->data[0] = stack_a->data[0];
	stack_b->size++;
	stack_a->size--;
	while (i < stack_a->size)
	{
		stack_a->data[i] = stack_a->data[i + 1];
		i++;
	}
}
