/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:39:23 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/30 15:52:28 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include "./libft/libft.h"

typedef struct s_stack
{
    int *data;
    int size; 
    int max;
} t_stack;




//--------------------------swap------------------------//

void ss(t_stack *a, t_stack *b);
void sb(t_stack *b);
void sa(t_stack *a);
void swap_top(t_stack *stack);


//--------------------------push------------------------//

void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);


//--------------------------rotate------------------------//

void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void rotate(t_stack *stack);

//--------------------------reverse_rotate------------------------//

void reverse_rotate(t_stack *stack);
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);

//--------------------------utils------------------------//

t_stack *init(int max);
void free_stack(t_stack *stack);

//--------------------------verif------------------------//

int	verif_double(t_stack *stack);

//--------------------------algo------------------------//

int is_sorted(t_stack *stack);
int find_median(t_stack *stack);
void push_chunks_to_b(t_stack *a, t_stack *b);
int find_min_index(t_stack *stack);
void move_to_top(t_stack *stack, int index, char stack_name);
void sort_three(t_stack *a);
void sort_five(t_stack *a, t_stack *b);
int find_best_target_in_a(t_stack *a, int value);
void push_back_to_a(t_stack *a, t_stack *b);
void align_stack(t_stack *a);
void push_swap(t_stack *a, t_stack *b);

void handle_single_argument(char *arg, t_stack **a);
void free_split(char **split_args);





#endif