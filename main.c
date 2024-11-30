/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:57:03 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/30 16:27:26 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_multi(t_stack *a, char **argv, int argc)
{
    int i = 1;

    while (i < argc)
    {
        a->data[a->size] = ft_atoi(argv[i]);
        a->size++;
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    if (argc < 2)
        return (0);

    if (argc == 2) 
    {
        handle_single_argument(argv[1], &a);
    }
    else
    {
        a = init(argc - 1);
        b = init(argc - 1);

        if (!a || !b)
        {
            write(1, "Error\n", 6); 
            return (1);
        }

        ft_multi(a,argv, argc); 
    }
 
    if (verif_double(a) == 1)
    {
        write(1, "Error\n", 6);
        free_stack(a);
        free_stack(b);
        return (1);
    }

    push_swap(a, b);

    free_stack(a);
    free_stack(b);

    return (0);
}
