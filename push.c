/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:22:10 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/27 15:54:00 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(int *a, int *b)
{
    int i;
    int size_a;
    int size_b;

    ft_putstr_fd("pa\n", 1);
	size_a = get_size(a);
	size_b = get_size(b);
    if (size_b == 0)
        return;
    i = size_a;
    while (i > 0)
    {
        a[i] = a[i - 1];
        i--;
    }
    a[0] = b[0];
    i = 0;
    while (i < size_b - 1)
    {
        b[i] = b[i + 1];
        i++;
    }
    b[size_b - 1] = 0;
}

void pb(int *a, int *b)
{
    int i;
    int size_a = get_size(a);
    int size_b = get_size(b);

    ft_putstr_fd("pb\n", 1);

    // Vérification si la pile a est vide
    if (size_a == 0)
        return;

    // Décaler les éléments de b pour faire de la place en haut de la pile b
    i = size_b;
    while (i > 0)
    {
        b[i] = b[i - 1];  // Décale les éléments vers le bas
        i--;
    }

    // Déplacer le premier élément de a en haut de b
    b[0] = a[0];

    // Décaler les éléments de a vers le bas
    i = 0;
    while (i < size_a - 1)
    {
        a[i] = a[i + 1];
        i++;
    }

    // Mettre la dernière valeur de a à 0 (sentinelle)
    a[size_a - 1] = 0;

    // Mettre à jour la sentinelle de b
    b[size_b] = 0;
}

