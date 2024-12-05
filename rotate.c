/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:48:14 by tomlimon          #+#    #+#             */
/*   Updated: 2024/12/05 20:55:13 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	int	i;
	int	temp;

	ft_putstr_fd("ra\n", 1);
	if (stack_a->size <= 1)
		return ;
	i = 0;
	temp = stack_a->data[0];
	while (i < stack_a->size - 1)
	{
		stack_a->data[i] = stack_a->data[i + 1];
		i++;
	}
	stack_a->data[stack_a->size - 1] = temp;
}

void	rb(t_stack *stack_b)
{
	int	i;
	int	temp;

	ft_putstr_fd("rb\n", 1);
	if (stack_b->size <= 1)
		return ;
	i = 0;
	temp = stack_b->data[0];
	while (i < stack_b->size - 1)
	{
		stack_b->data[i] = stack_b->data[i + 1];
		i++;
	}
	stack_b->data[stack_b->size - 1] = temp;
}

void	ra_rb(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr_fd("rr\n", 1);
	ra(stack_a);
	rb(stack_b);
}
