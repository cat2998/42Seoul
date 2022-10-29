/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:54:46 by jgwon             #+#    #+#             */
/*   Updated: 2022/10/29 17:05:04 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>

// void ft_atoi(char *argv)
// {
//     int i;
//     int minus;
//     int flag;
//     long result;

//     i = 0;
//     minus = 0;
//     flag = 0;
//     result = 0;
//     while (argv[i] != '\0')
//     {
//         if (argv[i] == ' ' && flag == 1)
//         {
//             if (minus == 1)
//                 result *= -1;
//             if (-2147483648 <= result && result <= 2147483647)
//                 //push stack
//             flag = 0;
//             result = 0;
//         }
//         else if ((argv[i] == '+' || argv[i] == '-') && flag == 0)
//         {
//             if (argv[i] == '-')
//                 minus = 1;
//             result = 0;
//         }
//         else if (48 <= argv[i] && argv[i] <= 57)
//         {
//             result = result * 10 + argv[i] - 48;
//             flag = 1;
//         }
//         else
//         {
//             write(1, "Error\n", 6);
//             //free
//             exit(0);
//         }
//         i++;
//     }
//     if (flag == 1)
//     {
//         if (minus == 1)            
//             result *= -1;
//         if (-2147483648 <= result && result <= 2147483647)
//         {
//             //push stack
//         }
//     }
//     return ;
// }

void ft_atoi(t_stack *stackA, char *argv)
{
    int     i;
	long    result;

	i = 0;
	result = 0;
	while ('0' <= argv[i] && argv[i] <= '9')
	{
		result *= 10;
		result += argv[i] - '0';
		i++;
	}
    t_node *node;

    node = malloc(sizeof(t_node) * 1);
	if (!node)
		return ;
	node->value = result;
    push_node(stackA, node);
	return ;
}

int main(int argc, char *argv[])
{
    t_stack *stackA;

    stackA = malloc(sizeof(t_stack) * 1);
	if (!stackA)
		return (0);
    init_stack(stackA);
    while (argc > 1)
    {
        ft_atoi(stackA, argv[argc - 1]);
        argc--;
    }
    printf("----stackA-----\n");
    print_stack(stackA);
    printf("----stackA swap-----\n");
    swap_stack(stackA);
    print_stack(stackA);
    printf("----stackA push node-----\n");
    t_node *node;
    node = malloc(sizeof(t_node) * 1);
	if (!node)
		return (0);
	node->value = 10;
    push_node(stackA, node);
    print_stack(stackA);
    printf("----stackA rotate-----\n");
    rotate_stack(stackA);
    print_stack(stackA);
    printf("----stackA rotate-----\n");
    rotate_stack(stackA);
    print_stack(stackA);
    printf("----stackA reverse rotate-----\n");
    reverse_rotate_stack(stackA);
    print_stack(stackA);
    // t_stack *stackB;
    // stackB = malloc(sizeof(t_stack) * 1);
	// if (!stackB)
	// 	return (0);
    // init_stack(stackB);
    // printf("----stackB-----\n");
    // print_stack(stackB);
    // printf("----stackB push node-----\n");
    // push_node(stackB, 100);
    // print_stack(stackB);
    // printf("----stackA push stackB-----\n");
    // printf("----stackB-----\n");
    // push_stack(stackA, stackB);
    // print_stack(stackB);
    // printf("----stackB push node-----\n");
    // push_node(stackB, 20);
    // print_stack(stackB);
    return (0);
    // quick_sork()
}