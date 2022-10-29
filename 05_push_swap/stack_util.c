/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:29:36 by jgwon             #+#    #+#             */
/*   Updated: 2022/10/29 22:27:48 by jgwon            ###   ########.fr       */
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

void	push_node(t_stack *stack, t_node *node)
{
	if (stack->size == 0)
	{
		node->next = node;
		node->prev = node;
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		node->next = stack->top;
		node->prev = stack->bottom;
		stack->top->prev = node;
		stack->bottom->next = node;
		stack->top = node;
	}
	stack->size += 1;
	return ;
}

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
	stackA->top = stackA->top->next;
	push_node(stackB, stackA->top->prev);
	stackA->top->prev = stackA->bottom;
	stackA->bottom->next = stackA->top;
	stackA->size -= 1;
	return ;
}

void	rotate_stack(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->bottom = stack->top;
	stack->top = stack->top->next;
	return ;
}

void	reverse_rotate_stack(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->top = stack->bottom;
	stack->bottom = stack->bottom->prev;
	return ;
}

void	print_stack(t_stack *stack)
{
	int	i;
	t_node	*node;

	i = 0;
	node = stack->top;
	while (stack->size > i)
	{
		printf("%d\n", node->value);
		node = node->next;
		i++;
	}
	return ;
}