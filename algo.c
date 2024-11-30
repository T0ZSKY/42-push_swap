/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:03:25 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/30 16:28:14 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *stack)
{
    int i;

    i = 0;
    while (i < stack->size - 1)
    {
        if (stack->data[i] > stack->data[i + 1])
            return (0);
        i++;
    }
    return (1);
}

int find_median_with_operations(t_stack *a, t_stack *b)
{
    int min_index;
    int rotations = 0;
    int median = 0;
    int total = a->size;


    while (a->size > total / 2)
    {
        min_index = find_min_index(a);
        move_to_top(a, min_index, 'a');
        pb(a, b);
        rotations++;
    }

    if (b->size > 0)
        median = b->data[b->size - 1];


    while (rotations--)
        pa(a, b);

    return median;
}


int find_min_index(t_stack *stack)
{
    int i;
    int min;
    int min_index;

    i = 0;
    min = stack->data[0];
    min_index = 0;
    while (i < stack->size)
    {
        if (stack->data[i] < min)
        {
            min = stack->data[i];
            min_index = i;
        }
        i++;
    }
    return (min_index);
}


void move_to_top(t_stack *stack, int index, char stack_name)
{
    int cost_up = index;
    int cost_down = stack->size - index;

    if (cost_up <= cost_down)
    {
        while (index > 0)
        {
            if (stack_name == 'a')
                ra(stack);
            else
                rb(stack);
            index--;  // Corriger l'index à chaque rotation
        }
    }
    else
    {
        while (index < stack->size - 1)
        {
            if (stack_name == 'a')
                rra(stack);
            else
                rrb(stack);
            index++;  // Corriger l'index dans la direction opposée
        }
    }
}



void sort_three(t_stack *a)
{
    if (a->data[0] > a->data[1] && a->data[1] < a->data[2] && a->data[0] < a->data[2])
        sa(a);
    else if (a->data[0] > a->data[1] && a->data[1] > a->data[2])
    {
        sa(a);
        rra(a);
    }
    else if (a->data[0] > a->data[1] && a->data[1] < a->data[2])
        ra(a);
    else if (a->data[0] < a->data[1] && a->data[1] > a->data[2] && a->data[0] < a->data[2])
    {
        sa(a);
        ra(a);
    }
    else if (a->data[0] < a->data[1] && a->data[1] > a->data[2])
        rra(a);
}

void sort_five(t_stack *a, t_stack *b)
{
    int min_index;

    min_index = find_min_index(a);
    move_to_top(a, min_index, 'a');
    pb(a, b);

    min_index = find_min_index(a);
    move_to_top(a, min_index, 'a');
    pb(a, b);

    sort_three(a);

    pa(a, b);
    pa(a, b);

    align_stack(a);
}

int find_best_target_in_a(t_stack *a, int value)
{
    int i;
    int best_index;
    int smallest_diff;
    int diff;

    i = 0;
    best_index = 0;
    smallest_diff = 2147483647;
    while (i < a->size)
    {
        diff = a->data[i] - value;
        if (diff > 0 && diff < smallest_diff)
        {
            smallest_diff = diff;
            best_index = i;
        }
        i++;
    }

    if (smallest_diff == 2147483647)
    {
        i = 0;
        while (i < a->size)
        {
            if (a->data[i] > a->data[best_index])
                best_index = i;
            i++;
        }
    }
    return (best_index);
}

void push_chunks_to_b(t_stack *a, t_stack *b)
{
    int median;

    median = find_median_with_operations(a, b);
    while (a->size > 0)
    {
        // Si la donnée est inférieure ou égale à la médiane, on la pousse dans b
        if (a->data[0] <= median)
            pb(a, b);
        else
            ra(a);  // Sinon, on la déplace en haut de la pile
    }
}



void push_back_to_a(t_stack *a, t_stack *b)
{
    int target_index;

    while (b->size > 0)
    {
        target_index = find_best_target_in_a(a, b->data[0]);
        move_to_top(a, target_index, 'a');
        pa(a, b);
    }
}

void align_stack(t_stack *a)
{
    int min_index;

    min_index = find_min_index(a);
    move_to_top(a, min_index, 'a');
}

void push_swap(t_stack *a, t_stack *b)
{
    if (is_sorted(a))
        return;

    if (a->size == 2)
        sa(a);
    else if (a->size == 3)
        sort_three(a);
    else if (a->size == 5)
        sort_five(a, b);
    else
    {
        push_chunks_to_b(a, b);
        push_back_to_a(a, b);
        align_stack(a);
    }
}
