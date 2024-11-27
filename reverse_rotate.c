/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:28:45 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/27 15:36:47 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(int *a)
{
    int size;
    int temp;
    int i;

    size = get_size(a);
    if (size < 2)
        return;
    temp = a[size - 1];
	i = size - 1;
    while (i > 0)
    {
        a[i] = a[i - 1];
		i--;
    }
    a[0] = temp;
    ft_putstr_fd("rra\n", 1);
}
void rrb(int *b)
{
    int size;
    int temp;
    int i;

    size = get_size(b);
    if (size < 2)
        return;
    temp = b[size - 1];
	i = size - 1;
    while (i > 0)
    {
        b[i] = b[i - 1];
		i--;
    }
    b[0] = temp;
    ft_putstr_fd("rrb\n", 1);
}