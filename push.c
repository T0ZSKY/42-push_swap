/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:22:10 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/27 21:59:25 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_stack *a, t_stack *b)
{
    int i;

    if (b->size == 0)
        return ;

    i = a->size;
    while (i > 0)
    {
        a->data[i] = a->data[i - 1];
        i--;
    }
    a->data[0] = b->data[0];
    
    i = 0;
    while (i < b->size - 1)
    {
        b->data[i] = b->data[i + 1];
        i++;
    }
    b->data[b->size - 1] = 0;

    a->size++;
    b->size--;
    write(1, "pa\n", 3);
}
void pb(t_stack *a, t_stack *b)
{
    int i;

    if (a->size == 0)
        return ;

    i = b->size;
    while (i > 0)
    {
        b->data[i] = b->data[i - 1];
        i--;
    }
    b->data[0] = a->data[0];
    
    i = 0;
    while (i < a->size - 1)
    {
        a->data[i] = a->data[i + 1];
        i++;
    }
    a->data[a->size - 1] = 0;

    a->size--;
    b->size++;
    write(1, "pb\n", 3);
}
