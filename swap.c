/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:39:14 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/27 15:52:57 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(int *a, int *b)
{
    int temp;
    
    if (*a == *b)
        return;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

void sa(int *a)
{
    int size;

    ft_putstr_fd("sa\n", 1);
	size = get_size(a);
    if (size < 2)
        return;
    
    swap(&a[0], &a[1]);
}

void sb(int *b)
{
    int size;

    ft_putstr_fd("sb\n", 1);
	size = get_size(b);
    if (size < 2)
        return;

    swap(&b[0], &b[1]);
}

void ss(int *a, int *b)
{
    ft_putstr_fd("ss\n", 1);
    sa(a);
    sb(b);
}

void print_stack(const char *name, int *stack)
{
    printf("Pile %s : ", name);
    for (int i = 0; stack[i]; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

int	main()
{
    int a[6] = {2, 1, 3, 6, 5, 8};
    int b[6] = {0};
	printf("Pile A : %d, %d, %d, %d, %d, %d\n", a[0], a[1], a[2], a[3], a[4], a[5]);
	printf("Pile B : %d, %d, %d, %d, %d, %d\n", b[0], b[1], b[2], b[3], b[4], b[5]);
	sa(a);
	pb(a, b);
	pb(a, b);
	pb(a, b);
	rr(a, b);
	printf("Pile A : %d, %d, %d, %d, %d, %d\n", a[0], a[1], a[2], a[3], a[4], a[5]);
	printf("Pile B : %d, %d, %d, %d, %d, %d\n", b[0], b[1], b[2], b[3], b[4], b[5]);

}

// int main(void)
// {
//     int a[5] = {3, 2, 1, 0};
//     int b[5] = {42, 15, 850, 2, 0};

//     printf("=== Test des fonctions ===\n");

//     printf("\nÉtat initial :\n");
//     print_stack("A", a);
//     print_stack("B", b);

//     sa(a);
//     printf("\nAprès sa :\n");
//     print_stack("A", a);
//     print_stack("B", b);

//     sb(b);
//     printf("\nAprès sb :\n");
//     print_stack("A", a);
//     print_stack("B", b);

//     pa(a, b);
//     printf("\nAprès pa :\n");
//     print_stack("A", a);
//     print_stack("B", b);

// 	pb(a, b);
//     printf("\nAprès pb :\n");
//     print_stack("A", a);
//     print_stack("B", b);
	
// 	ra(a);
//     printf("\nAprès ra :\n");
//     print_stack("A", a);
//     print_stack("B", b);
	
// 	rb(b);
//     printf("\nAprès rb :\n");
//     print_stack("A", a);
//     print_stack("B", b);
		
// 	rr(a, b);
//     printf("\nAprès rr :\n");
//     print_stack("A", a);
//     print_stack("B", b);

// 	rra(a);
//     printf("\nAprès rra :\n");
//     print_stack("A", a);
//     print_stack("B", b);
	
// 	rrb(b);
//     printf("\nAprès rrb :\n");
//     print_stack("A", a);
//     print_stack("B", b);
//     return 0;
// }
