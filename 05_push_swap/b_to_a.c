/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:28:11 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/02 03:21:46 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

t_node  *find_min_node(t_stack *stack)
{
    int i;
    t_node *min_node;
    t_node *node;

    i = 0;
    node = stack->top;
    min_node = stack->top;
    while(i < stack->size)
    {
        if (min_node->value > node->value)
            min_node = node;
        node = node->next;
        i++;
    }
    return (min_node);
}

int  find_min_node_idx(t_stack *stack)
{
    int i;
    int min_node_idx;
    t_node *min_node;
    t_node *node;

    i = 0;
    node = stack->top;
    min_node = stack->top;
    while(i < stack->size)
    {
        if (min_node->value > node->value)
        {
            min_node = node;
            min_node_idx = i;
        }
        node = node->next;
        i++;
    }
    return (min_node_idx);
}

int is_sort(t_stack *stack, t_node *node)
{
    int i;

    i = 0;
    while (i < stack->size - 1)
    {
        if (node->value > node->next->value)
            return (0);
        node = node->next;
        i++;
    }
    return (1);
}

int is_reverse_sort(t_stack *stack, t_node *node)
{
    int i;

    i = 0;
    while (i < stack->size - 1)
    {
        if (node->value > node->prev->value)
            return (0);
        node = node->prev;
        i++;
    }
    return (1);
}

int find_dest(t_stack *stackA, t_stack *stackB)
{
    int i;
    int j;
    t_node  *node;

    i = 0;
    while (i < stackA->size)
    {
        push_stack(stackB, stackA);
        node = find_min_node(stackA);
        if (is_sort(stackA, node) || is_reverse_sort(stackA, node))
        {
            j = 0;
            push_stack(stackA, stackB);
            while (j++ < i)
                reverse_rotate_stack(stackA);
            return (i);
        }
        else
        {
            push_stack(stackA, stackB);
            rotate_stack(stackA);
        }
        i++;
    }
    return (0);
}

int ft_max(int a, int b)
{
    if (a > b) 
        return (a);
    else
        return (b);
}

int ft_min(int a, int b)
{
    if (a < b) 
        return (a);
    else
        return (b);
}

int    find_min(t_node *node)
{
    int i;
    int key;
    int values[4];

    values[0] = ft_max(node->info[0], node->info[1]);
    values[1] = node->info[0] + node->info[3];
    values[2] = node->info[2] + node->info[1];
    values[3] = ft_max(node->info[2], node->info[3]);
    i = 0;
    key = i;
    while (i < 4)
    {
        if (values[key] > values[i])
            key = i;
        i++;
    }
    node->info[6] = key;
    return (values[key]);
}

void    set_node_info(t_stack *stackA, t_stack *stackB, int position)
{
    int ra;
    int rra;
    int rb;
    int rrb;

    ra = find_dest(stackA, stackB);
    rra = stackA->size - ra;
    rb = position;
    rrb = stackB->size - rb;
    stackB->top->info[0] = ra;
    stackB->top->info[1] = rb;
    stackB->top->info[2] = rra;
    stackB->top->info[3] = rrb;
    return ;
}

void    set_node_key_info(t_node *node)
{
    if (node->info[6] == 0)
    {
        node->info[4] = ft_min(node->info[0], node->info[1]);
        node->info[0] = node->info[0] - node->info[4];
        node->info[1] = node->info[1] - node->info[4];
        node->info[2] = 0;
        node->info[3] = 0;
    }
    else if (node->info[6] == 1)
    {
        node->info[1] = 0;
        node->info[2] = 0;
    }
    else if (node->info[6] == 2)
    {
        node->info[0] = 0;
        node->info[3] = 0;
    }
    else if (node->info[6] == 3)
    {
        node->info[5] = ft_min(node->info[2], node->info[3]);
        node->info[2] = node->info[2] - node->info[5];
        node->info[3] = node->info[3] - node->info[5];
        node->info[0] = 0;
        node->info[1] = 0;
    }
    return ;
}

void    execute(t_stack *stackA, t_stack *stackB, t_node *node)
{
    while (node->info[0]-- > 0)
    {
        rotate_stack(stackA);
        printf("ra\n");
    }
    while (node->info[1]-- > 0)
    {
        rotate_stack(stackB);
        printf("rb\n");
    }
    while (node->info[2]-- > 0)
    {
        reverse_rotate_stack(stackA);
        printf("rra\n");
    }
    while (node->info[3]-- > 0)
    {
        reverse_rotate_stack(stackB);
        printf("rrb\n");
    }
    while (node->info[4]-- > 0)
    {
        rotate_stack(stackA);
        rotate_stack(stackA);
        printf("rr\n");
    }
    while (node->info[5]-- > 0)
    {
        reverse_rotate_stack(stackA);
        reverse_rotate_stack(stackB);
        printf("rrr\n");
    }
    push_stack(stackB, stackA);
    printf("pa\n");
    return ;
}

void    b_to_a(t_stack *stackA,t_stack *stackB)
{
    int i;
    int node_min;
    int total_min;
    t_node  *node;

    i = 0;
    total_min = stackA->size + stackB->size;
    while (i < stackB->size)
    {
        set_node_info(stackA, stackB, i);
        // printf("ra:%d rb:%d rra:%d rrb:%d\n", ra, rb, rra, rrb);
        node_min = find_min(stackB->top);
        // printf("min:%d\n", node_min);
        if (total_min > node_min)
        {
            total_min = node_min;
            node = stackB->top;
        }
        rotate_stack(stackB);
        i++;
    }
    set_node_key_info(node);
    execute(stackA, stackB, node);
    // printf("min:%d\n", total_min);
    // printf("idx:%d\n", node_idx);
    return ;
}