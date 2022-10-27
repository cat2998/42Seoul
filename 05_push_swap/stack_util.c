/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:29:36 by jgwon             #+#    #+#             */
/*   Updated: 2022/10/28 01:50:37 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void    init_stack(t_stack *s)
{
    s->size = 0;
	s->top = 0;
	s->bottom = 0;
}

int	push_node(t_stack *stack, int n)
{
	t_node *node;

    node = malloc(sizeof(t_node) * 1);
	if (!node)
		return (0);
	stack->size += 1;
	node->value = n;
	node->prev = 0;
	if (stack->top == 0)
	{
		stack->top = node;
		stack->bottom = node;
		node->next = 0;
	}
	else
	{
		stack->top->prev = node;
		node->next = stack->top;
		stack->top = node;
	}
	return (1);
}

// void	swap_stack(t_stack *stack)
// {
// 	if (stack->size == 1)
// 		return ;
// 	stack->top = stack->top->next;
// 	stack->top->prev->prev = stack->top;
// 	stack->top->prev->next = stack->top->next;
// 	stack->top->next = stack->top->prev;
// 	stack->top->prev = 0;
// 	return ;
// }

void	swap_stack(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = tmp;
	return ;
}

void	push_stack(t_stack *stackA, t_stack *stackB)
{
	if (stackA->size == 0)
		return ;
	if (stackB->top == 0)
	{
		stackA->top = stackA->top->next;
		stackB->top = stackA->top->prev;
		stackB->bottom = stackB->top;
		stackB->top->next = 0;	
	}
	else
	{
		stackA->top = stackA->top->next;
		stackB->top->prev = stackA->top->prev;
		stackB->top->prev->next = stackB->top;
		stackB->top = stackB->top->prev;
		stackA->top->prev = 0;
	}
	stackB->size += 1;
	stackA->size -= 1;
	return ;
}

void	rotate_stack(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	
}

void	print_stack(t_stack *stack)
{
	t_node	*node;

	if (stack->size == 0)
		return ;
	node = stack->top;
	while (node->next != 0)
	{
		printf("%d\n", node->value);
		node = node->next;
	}
	printf("%d\n", node->value);
	return ;
}