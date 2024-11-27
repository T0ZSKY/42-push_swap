/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:08:36 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/27 21:34:35 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init(int max)
{
    t_stack *stack = malloc(sizeof(t_stack));
    if (!stack)
        return NULL;

    stack->data = malloc(sizeof(int) * max);
    if (!stack->data)
    {
        free(stack);
        return NULL;
    }
    stack->max = max;
    return stack;
}
void free_stack(t_stack *stack)
{
    if (stack)
    {
        free(stack->data);
        free(stack);
    }
}
