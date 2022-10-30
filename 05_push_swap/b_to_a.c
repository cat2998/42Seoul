/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:28:11 by jgwon             #+#    #+#             */
/*   Updated: 2022/10/30 21:10:30 by jgwon            ###   ########.fr       */
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
        if (is_sort(stackA, node) == 1)
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

// void    get_arr(int *arr, int *i, int a, int b)
// {
//     int r;
//     r = 0;
//     while (a > 0 && b > 0)
//     {
//         r++;
//         a--;
//         b--;
//     }
//     arr[(*i)++] = r;
//     arr[(*i)++] = a;
//     arr[(*i)++] = r;
//     arr[(*i)++] = b;
//     return ;
// }

// void    find_min(int ra, int rra, int rb, int rrb)
// {
//     int i;
//     int min;
//     int arr[12];
//     i = 0;
//     arr[i++] = ra;
//     arr[i++] = rrb;
//     arr[i++] = rra;
//     arr[i++] = rb;
//     get_arr(arr, &i, ra, rb);
//     get_arr(arr, &i, rra, rrb);
//     i = 0;
//     min = arr[0] + arr[1];
//     while (i < 12)
//     {
//         if (min > arr[i] + arr[i + 1])
//         {
//         }
//     }
// }
int ft_max(int a,int b){
    if(a  > b ) 
        return a;
    else
        return b;
}

int    find_min(t_node *node)
{
    int i;
    int key;
    int values[4];

    values[0] = ft_max(node->info[0],node->info[1]);
    values[1] = node->info[0] + node->info[3];
    values[2] = node->info[2] + node->info[1];
    values[3] = ft_max(node->info[2],node->info[3]);
    i = 0;
    key = i;
    while (i < 4)
    {
        if (values[key] > values[i])
            key = i;
        i++;
    }
    node->info[4] = key;
    return (values[key]);
}

void    b_to_a(t_stack *stackA,t_stack *stackB)
{
    int ra;
    int rra;
    int rb;
    int rrb;

    int i;
    int j;
    int node_min;
    int total_min;
    int node_idx;
    t_node  *node;

    i = 0;
    j = 0;
    total_min = ft_max(stackA->size, stackB->size);
    while (i < stackB->size)
    {
        ra = find_dest(stackA, stackB);
        rra = stackA->size - ra;
        rb = i;
        rrb = stackB->size - rb;
        stackB->top->info[0] = ra;
        stackB->top->info[1] = rb;
        stackB->top->info[2] = rra;
        stackB->top->info[3] = rrb;
        printf("ra:%d rb:%d rra:%d rrb:%d\n", ra, rb, rra, rrb);
        node_min = find_min(stackB->top);
        printf("min:%d\n", node_min);
        if (total_min > node_min)
        {
            total_min = node_min;
            node_idx = i;
            // node = stackB->top;
        }
        rotate_stack(stackB);
        i++;
    }
    printf("min:%d\n", total_min);
    printf("idx:%d\n", node_idx);
    // printf("node_value:%d, node_key:%d\n", node->value, node->info[4]);
    i = 0;
    node = stackB->top;
    while (i < stackB->size)
    {
        if (i == node_idx)
        {
            printf("node_info[4]:%d\n", node->info[4]);
            if (node->info[4] == 0)
            {
                while (node->info[0] > 0 && node->info[1] > 0)
                {
                    node->info[0]--;
                    node->info[1]--;
                    rotate_stack(stackA);
                    rotate_stack(stackB);
                    printf("rr\n");
                }
                while (node->info[0] > 0)
                {
                    node->info[0]--;
                    rotate_stack(stackA);
                    printf("ra\n");
                }
                while (node->info[1] > 0)
                {
                    node->info[1]--;
                    rotate_stack(stackB);
                    printf("rb\n");
                }
            }
            else if (node->info[4] == 1)
            {
                while (node->info[0] > 0)
                {
                    node->info[0]--;
                    rotate_stack(stackA);
                    printf("ra\n");
                }
                while (node->info[3] > 0)
                {
                    node->info[3]--;
                    reverse_rotate_stack(stackB);
                    printf("rrb\n");
                }
            }
            else if (node->info[4] == 2)
            {
                while (node->info[1] > 0)
                {
                    node->info[1]--;
                    rotate_stack(stackB);
                    printf("rb\n");
                }
                while (node->info[2] > 0)
                {
                    node->info[2]--;
                    reverse_rotate_stack(stackA);
                    printf("rra\n");
                }
            }
            else if (node->info[4] == 3)
            {
                while (node->info[2] > 0 && node->info[3] > 0)
                {
                    node->info[2]--;
                    node->info[3]--;
                    reverse_rotate_stack(stackA);
                    reverse_rotate_stack(stackB);
                    printf("rrr\n");
                }
                while (node->info[2] > 0)
                {
                    node->info[2]--;
                    reverse_rotate_stack(stackA);
                    printf("rra\n");
                }
                while (node->info[3] > 0)
                {
                    node->info[3]--;
                    reverse_rotate_stack(stackB);
                    printf("rrb\n");
                }
            }
            break;
        }
        else
            node = node->next;
    }
    push_stack(stackB, stackA);
    printf("pb\n");
    return ;
}