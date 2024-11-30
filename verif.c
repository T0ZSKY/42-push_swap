/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:17:37 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/30 15:52:24 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_split(char **split_args)
{
    int i = 0;

    while (split_args[i])
    {
        free(split_args[i]);
        i++;
    }
    free(split_args);
}

int verif_double(t_stack *stack)
{
    int i;
    int j;

    if (!stack || !stack->data)
        return (0);

    i = 0;
    while (i < stack->size)
    {
        j = i + 1;
        while (j < stack->size)
        {
            if (stack->data[i] == stack->data[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}


