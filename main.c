/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:57:03 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/27 22:09:18 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int i;
    if (argc < 2)
    {
        write(1, "error\n", 6);
        return (1);
    }
    a = init(argc - 1);
    b = init(argc - 1);
    i = 1;
    if (!a || !b)
    {
        write(1, "Error\n", 6);
        return (1);
    }
    while(i < argc)
    {
        a->data[a->size] = ft_atoi(argv[i]);
        a->size++;       
        i++;
    }
    printf("Avant push\n");
    printf("A:%d\n", a->data[0]);
    printf("A:%d\n", a->data[1]);
    printf("A:%d\n", a->data[2]);
	write(1, "\n", 1);
    printf("B:%d\n", b->data[0]);
    printf("B:%d\n", b->data[1]);
    printf("B:%d\n", b->data[2]);
    rra(a);
    printf("Apres push\n");
    printf("A:%d\n", a->data[0]);
    printf("A:%d\n", a->data[1]);
    printf("A:%d\n", a->data[2]);
	write(1, "\n", 1);
    printf("B:%d\n", b->data[0]);
    printf("B:%d\n", b->data[1]);
    printf("B:%d\n", b->data[2]);
    free_stack(a);
    free_stack(b);
}