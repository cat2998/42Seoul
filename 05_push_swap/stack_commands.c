/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:15:02 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/03 22:57:07 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	else if (stackA->size == 1)
	{
		push_node(stackB, stackA->top);
		stackA->top = 0;
		stackA->bottom = 0;
		stackA->size -= 1;
		return ;
	}
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
