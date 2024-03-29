/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:54:46 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/04 00:55:23 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack *stackA, t_stack *stackB)
{
	t_node	*node;
	t_node	*next_node;

	if (stackA->size > 0)
	{
		next_node = stackA->top;
		while (stackA->size-- > 0)
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

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = malloc(sizeof(t_stack) * 1);
	if (!stack_a)
		return (0);
	stack_b = malloc(sizeof(t_stack) * 1);
	if (!stack_b)
	{
		free(stack_a);
		return (0);
	}
	init_stack(stack_a);
	init_stack(stack_b);
	push_swap(stack_a, stack_b, argv, argc);
	free_all(stack_a, stack_b);
	return (0);
}
