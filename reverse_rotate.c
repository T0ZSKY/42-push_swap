/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:28:45 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/27 22:08:56 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_stack *stack)
{
    int i;
    int temp;

    if (stack->size < 2)
        return;

    temp = stack->data[stack->size - 1];
    i = stack->size - 1;
    while (i > 0)
    {
        stack->data[i] = stack->data[i - 1];
        i--;
    }

    stack->data[0] = temp;
}
void rra(t_stack *a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}
void rrb(t_stack *b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}
void rrr(t_stack *a, t_stack *b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}
