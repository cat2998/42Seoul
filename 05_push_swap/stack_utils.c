/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:29:36 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/04 00:22:03 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_node(t_node *node)
{
	int	i;

	node->value = 0;
	node->prev = 0;
	node->next = 0;
	i = 0;
	while (i++ < 7)
		node->info[i] = 0;
	return ;
}

void	init_stack(t_stack *s)
{
	s->size = 0;
	s->top = 0;
	s->bottom = 0;
	return ;
}

int	find_node(t_stack *stack, t_node *node)
{
	int		i;
	t_node	*n;

	if (stack->size > 0)
	{
		i = 0;
		n = stack->top;
		while (i < stack->size)
		{
			if (n->value == node->value)
				return (1);
			n = n->next;
			i++;
		}
	}
	return (0);
}

t_node	*find_min_node(t_stack *stack)
{
	int		i;
	t_node	*node;
	t_node	*min_node;

	i = 0;
	node = stack->top;
	min_node = stack->top;
	while (i < stack->size)
	{
		if ((node->value < 0 && min_node->value >= 0) \
			|| (!(node->value < 0 && min_node->value >= 0) \
			&& (min_node->value > node->value)))
			min_node = node;
		node = node->next;
		i++;
	}
	return (min_node);
}

int	find_min_node_idx(t_stack *stack)
{
	int		i;
	t_node	*node;
	t_node	*min_node;
	int		min_node_idx;

	i = 0;
	node = stack->top;
	min_node = stack->top;
	min_node_idx = 0;
	while (i < stack->size)
	{
		if ((node->value < 0 && min_node->value >= 0) \
			|| (!(node->value < 0 && min_node->value >= 0) \
			&& (min_node->value > node->value)))
		{
			min_node = node;
			min_node_idx = i;
		}
		node = node->next;
		i++;
	}
	return (min_node_idx);
}
