/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:39:23 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/27 15:37:17 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include "./libft/libft.h"

//--------------------------swap------------------------//

void swap(int *a, int *b);
void sa(int *a);
void sb(int *b);
void ss(int *a, int *b);

//--------------------------push------------------------//

void	pa(int *a, int *b);
void pb(int *a, int *b);

//--------------------------rotate------------------------//

void ra(int *a);
void rb(int *b);
void	rr(int *a, int *b);

//--------------------------reverse_rotate------------------------//

void rra(int *a);
void rrb(int *b);

//--------------------------utils------------------------//

int get_size(int *arr);

#endif