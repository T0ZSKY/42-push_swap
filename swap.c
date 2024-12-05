/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:48:02 by tomlimon          #+#    #+#             */
/*   Updated: 2024/12/04 00:48:06 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	ft_putstr_fd("sa\n", 1);
	ft_swap(&stack_a->data[0], &stack_a->data[1]);
}

void	sb(t_stack *stack_b)
{
	ft_putstr_fd("sb\n", 1);
	ft_swap(&stack_b->data[0], &stack_b->data[1]);
}

void	sa_sb(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr_fd("ss\n", 1);
	sa(stack_a);
	sb(stack_b);
}

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}
