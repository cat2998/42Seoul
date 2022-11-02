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

int get_result(char *split, long *result)
{
    int i;
    int minus;

    i = 0;
    minus = 0;
    while (split[i] != '\0')
    {
        if (i == 0 && split[i] == '-')
             minus = -1;
        else if ('0' <= split[i] && split[i] <= '9')
        {
            *result = *result * 10;
            *result = *result + split[i] - '0';
        }
        else
            return (1);
        if (*result > 2147483647 && minus == 0)
			return (1);
		if (*result > 2147483648 && minus == -1)
			return (1);
        i++;
    }
    if (minus == -1)
        *result = *result * minus;
    return (0);
}

int into_stack(t_stack *stackA, char *argv)
{
    int     i;
	long    result;
    char    **split;
    t_node *node;

    split = ft_split(argv, ' ');
    i = 0;
    while (split != 0 && split[i] != 0)
    {
        result = 0;
        if (get_result(split[i], &result))
        {
            ft_split_all_free(split);
            return (1);
        }
        node = malloc(sizeof(t_node) * 1);
        if (!node)
        {
            ft_split_all_free(split);
            return (1);
        }
        init_node(node);
        node->value = result;
        if (find_node(stackA, node))
        {
            ft_split_all_free(split);
            return (1);
        }
        push_node(stackA, node);
        i++;
    }
    ft_split_all_free(split);
	return (0);
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

int is_sort_stack(t_stack *stack)
{
    if (stack->size > 0 && is_sort(stack, stack->top))
        return (1);
    if (stack->size > 0 && is_reverse_sort(stack, stack->bottom))
    {
        while (stack->size-- > 0)
        {
            rotate_stack(stack);
            printf("ra\n");
        }
        return (1);
    }
    return (0);
}

void    free_all(t_stack *stackA, t_stack *stackB)
{
    t_node  *node;
    t_node  *next_node;

    if (stackA->size > 0)
    {
        next_node = stackA->top;
        while(stackA->size-- > 0)
        {
            node = next_node;
            next_node = node->next;
            free(node);
        }
    }
    free(stackA);
    free(stackB);
    return ;
}

// int make_stack(t_stack *stackA, t_stack *stackB)
// {
//     stackA = malloc(sizeof(t_stack) * 1);
// 	if (!stackA)
// 		return (1);
//     stackB = malloc(sizeof(t_stack) * 1);
// 	if (!stackB)
//     {
//         free(stackA);
// 		return (1);
//     }
//     init_stack(stackA);printf("stackA->size:%d\n", stackA->size);
//     init_stack(stackB);
//     return (0);
// }

int main(int argc, char *argv[])
{
    t_stack *stackA;
    t_stack *stackB;

    // if (make_stack(stackA, stackB))
    //     return (0);
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
        if (into_stack(stackA, argv[argc - 1]))
        {
            printf("Error\n");
            free_all(stackA, stackB);
            return (0);
        }
        argc--;
    }
    if (stackA->size == 0 || is_sort_stack(stackA))
    {
        free_all(stackA, stackB);
        return (0);
    }
    if (a_to_b(stackA, stackB))
    {
        free_all(stackA, stackB);
        return (0);
    }
    while (stackB->size > 0)
        b_to_a(stackA, stackB);
    sort_stack(stackA);
    printf("----stackA----\n");
    print_stack(stackA);
    free_all(stackA, stackB);
    return (0);
}
