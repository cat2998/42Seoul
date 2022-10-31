/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:54:46 by jgwon             #+#    #+#             */
/*   Updated: 2022/10/31 02:07:17 by jgwon            ###   ########.fr       */
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

void    split_lis_stack(t_stack *stackA, t_stack *stackB, int *lis)
{
    int i;
    int j;
    t_node  *node;

    i = 0;
    j = 0;
    while (i++ < stackA->size + stackB->size)
    {
        node = stackA->top;
        if (lis[j] == node->value)
        {
            printf("ra\n");
            rotate_stack(stackA);
            j++;
        }
        else
        {
            printf("pb\n");
            push_stack(stackA, stackB);
        }
    }
    return ;
}

int    split_stack(t_stack *stackA, t_stack *stackB)
{
    int *lis;
    int size;

    lis = malloc(sizeof(int) * stackA->size);
    if (!lis)
        return (0);
    find_lis(stackA, lis);
    split_lis_stack(stackA, stackB, lis);
    free(lis);
    return (1);
}

int main(int argc, char *argv[])
{
    int *sort_list;
    t_stack *stackA;
    t_stack *stackB;

    stackA = malloc(sizeof(t_stack) * 1);
	if (!stackA)
		return (0);
    stackB = malloc(sizeof(t_stack) * 1);
	if (!stackB)
    {
        free(stackA);
		return (0);
    }
    init_stack(stackA);
    init_stack(stackB);
    while (argc > 1)
    {
        ft_atoi(stackA, argv[argc - 1]);
        argc--;
    }
    /*오름차순인지, 내림차순인지 확인 필요*/
    
    sort_list = quick_sort_stack(stackA);
    // printf("----sort----\n");
    // for(int i = 0; i < stackA->size; i++)
    // {
    //     printf("%d ", sort_list[i]);
    // }
    // printf("\n");
    split_stack(stackA, stackB);
    // printf("----stackA----\n");
    // print_stack(stackA);
    // printf("----stackB----\n");
    // print_stack(stackB);
    while (stackB->size > 0)
    {
        b_to_a(stackA, stackB);
        // printf("----stackA----\n");
        // print_stack(stackA);
        // printf("----stackB----\n");
        // print_stack(stackB);
    }
    printf("----stackA----\n");
    print_stack(stackA);
    return (0);
}
