/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:48:19 by tomlimon          #+#    #+#             */
/*   Updated: 2024/12/04 00:48:31 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a)
{
	int	i;
	int	temp;

	if (stack_a->size < 2)
		return ;
	i = stack_a->size - 1;
	temp = stack_a->data[stack_a->size - 1];
	while (i > 0)
	{
		stack_a->data[i] = stack_a->data[i - 1];
		i--;
	}
	stack_a->data[0] = temp;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *stack_b)
{
	int	i;
	int	temp;

	if (stack_b->size < 2)
		return ;
	i = stack_b->size - 1;
	temp = stack_b->data[stack_b->size - 1];
	while (i > 0)
	{
		stack_b->data[i] = stack_b->data[i - 1];
		i--;
	}
	stack_b->data[0] = temp;
	ft_putstr_fd("rrb\n", 1);
}

void	rra_rrb(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr_fd("rra\n", 1);
	rra(stack_a);
	rrb(stack_b);
}
