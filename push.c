/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:22:10 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/30 16:22:43 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_stack *a, t_stack *b)
{
    int i;

    if (b->size == 0)
        return ;

    // Shift elements in stack A to make space for the new element at the top
    i = a->size;
    while (i > 0)
    {
        a->data[i] = a->data[i - 1];
        i--;
    }

    // Add the top element of stack B to the top of stack A
    a->data[0] = b->data[0];

    // Shift elements in stack B to remove the top element
    i = 0;
    while (i < b->size - 1)
    {
        b->data[i] = b->data[i + 1];
        i++;
    }
    b->data[b->size - 1] = 0;  // Optional, to clear the last element

    // Update sizes
    a->size++;
    b->size--;

    write(1, "pa\n", 3);
}

void pb(t_stack *a, t_stack *b)
{
    int i;

    if (a->size == 0)
        return ;

    // Shift elements in stack B to make space for the new element at the top
    i = b->size;
    while (i > 0)
    {
        b->data[i] = b->data[i - 1];
        i--;
    }

    // Add the top element of stack A to the top of stack B
    b->data[0] = a->data[0];

    // Shift elements in stack A to remove the top element
    i = 0;
    while (i < a->size - 1)
    {
        a->data[i] = a->data[i + 1];
        i++;
    }
    a->data[a->size - 1] = 0;  // Optional, to clear the last element

    // Update sizes
    a->size--;
    b->size++;

    write(1, "pb\n", 3);
}

