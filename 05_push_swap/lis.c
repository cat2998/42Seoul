/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:52:40 by jgwon             #+#    #+#             */
/*   Updated: 2022/10/30 15:32:30 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int lower_bound(int *list, int size, int target)
{
    int start;
    int end;
	int mid;

    start = 0;
    end = size-1;
	while (end > start)
	{
		mid = (start + end) / 2; 
		if (list[mid] >= target)
			end = mid;
		else start = mid + 1;
	}
	return end;
}

int find_lis_size(int *lis, int *index, t_stack *stack)
{
    int i;
    int size;
    t_node *node;

    i = 0;
    size = 0;
    node = stack->top;
    while (i < stack->size)
    {
        if (size == 0 || lis[size - 1] < node->value)
        {
            index[i++] = size;
            lis[size++] = node->value;
        }
        else
        {
            index[i++] = lower_bound(lis, size, node->value);
            lis[lower_bound(lis, size, node->value)] = node->value;
        }
        node = node->next;
    }
    printf("----before lis----\n");
    for (int j = 0; j < i; j++)
    {
        printf("%d ", lis[j]);
    }
    printf("\n");
    printf("----index----\n");
    for (int j = 0; j < i; j++)
    {
        printf("%d ", index[j]);
    }
    printf("\n");
    return (size);
}

// void    make_lis(int *lis, int lis_size, int *index, t_stack *stack)
// {
//     int i;
//     int find;
//     t_node  *node;

//     find = 0;
//     while (find < lis_size)
//     {
//         i = 0;
//         node = stack->top;
//         while (i < stack->size)
//         {
//             if (index[i] == find)
//             {
//                 lis[find] = node->value;
//                 break;
//             }
//             node = node->next;
//             i++;
//         }
//         find++;
//     }
//     return ;
// }

void    make_lis(int *lis, int lis_size, int *index, t_stack *stack)
{
    int i;
    int find;
    t_node  *node;

    i = stack->size - 1;
    find = lis_size - 1;
    node = stack->bottom;
    while (i >= 0)
    {
        if (index[i] == find)
        {
            lis[find] = node->value;
            find--;
        }
        node = node->prev;
        i--;
    }
    return ;
}

int    find_lis(t_stack *stack, int *lis)
{
    int *index;
    int lis_size;

    index = malloc(sizeof(int) * stack->size);
	if (!index)
		return (0);
    lis_size = find_lis_size(lis, index, stack);
    printf("lis_size:%d\n", lis_size);
    make_lis(lis, lis_size, index, stack);
    printf("----after lis----\n");
    for (int i = 0; i < lis_size; i++)
        printf("%d ", lis[i]);
    printf("\n");
    free(index);
    return (1);
}
