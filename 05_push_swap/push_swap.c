/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:54:46 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/02 03:54:32 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>

void ft_atoi(t_stack *stackA, char *argv)
{
    int     i;
    int     j;
	long    result;
    char    **split;
    t_node *node;

    split = ft_split(argv, ' ');
    i = 0;
    while (split[i] != 0)
    {
        j = 0;
        result = 0;
        while (split[i][j] != '\0')
        {
            if ('0' <= split[i][j] && split[i][j] <= '9')
            {
                result *= 10;
                result += split[i][j] - '0';
            }
            j++;
        }
        node = malloc(sizeof(t_node) * 1);
        if (!node)
            return ;
        init_node(node);
        node->value = result;
        push_node(stackA, node);
        i++;
    }
    
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

    lis = malloc(sizeof(int) * stackA->size);
    if (!lis)
        return (0);
    find_lis(stackA, lis);
    split_lis_stack(stackA, stackB, lis);
    free(lis);
    return (1);
}

void    sort_stack(t_stack *stack)
{
    int idx;
    int r_idx;

    idx = find_min_node_idx(stack);
    r_idx = stack->size - idx;
    if (idx < r_idx)
    {
        while (idx-- > 0)
        {
            rotate_stack(stack);
            printf("ra\n");
        }
    }
    else
    {
        while (r_idx-- > 0)
        {
            reverse_rotate_stack(stack);
            printf("rra\n");
        }
    }
    return ;
}

void    free_all(t_stack *stackA, t_stack *stackB)
{
    t_node  *node;
    t_node  *next_node;

    next_node = stackA->top;
    while(stackA->size-- > 0)
    {
        node = next_node;
        next_node = node->next;
        free(node);
    }
    free(stackA);
    free(stackB);
    return; 
}

int main(int argc, char *argv[])
{
    // int *sort_list;
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
    if (stackA->size > 0 && is_sort(stackA, stackA->top))
        return (0);
    if (stackA->size > 0 && is_reverse_sort(stackA, stackA->bottom))
    {
        while (stackA->size-- > 0)
        {
            rotate_stack(stackA);
            printf("ra\n");
        }
        return (0);
    }
    // sort_list = quick_sort_stack(stackA);
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
    sort_stack(stackA);
    printf("----stackA----\n");
    print_stack(stackA);
    free_all(stackA, stackB);
    // system("leaks a.out");
    return (0);
}
