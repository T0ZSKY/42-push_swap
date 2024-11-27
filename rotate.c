/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:12:15 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/27 15:26:14 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(int *a)
{
    int size;
    int temp;
    int i;

    size = get_size(a);
	i = 0;
    if (size < 2)
        return;
    temp = a[0];
    while (i < size - 1)
    {
        a[i] = a[i + 1];
		i++;
    }
    a[size - 1] = temp;
    ft_putstr_fd("ra\n", 1);
}
void rb(int *b)
{
    int size;
    int temp;
    int i;

    size = get_size(b);
	i = 0;
    if (size < 2)
        return;
    temp = b[0];
    while (i < size - 1)
    {
        b[i] = b[i + 1];
		i++;
    }
    b[size - 1] = temp;
    ft_putstr_fd("rb\n", 1);
}

void	rr(int *a, int *b)
{
	ft_putstr_fd("rr\n", 1);
	ra(a);
	rb(b);
}