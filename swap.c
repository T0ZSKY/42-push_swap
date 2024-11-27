/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:39:14 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/27 21:56:59 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_top(t_stack *stack)
{
    if (stack->size < 2)
        return;
    int temp = stack->data[0];
    stack->data[0] = stack->data[1];
    stack->data[1] = temp;
}

void sa(t_stack *a)
{
    swap_top(a);
    write(1, "sa\n", 3);
}
void sb(t_stack *b)
{
    swap_top(b);
    write(1, "sb\n", 3);
}
void ss(t_stack *a, t_stack *b)
{
    swap_top(a);
    swap_top(b);
    write(1, "ss\n", 3);
}
