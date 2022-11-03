/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:15:11 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/03 22:57:01 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_stack_mid_lis(t_stack *stackA, t_stack *stackB, int mid_lis)
{
	if (stackA->size + stackB->size > 100)
	{
		if (stackB->top->value < mid_lis)
		{
			write(1, "rb\n", 3);
			rotate_stack(stackB);
		}
	}
	return ;
}

void	split_stack_lis(t_stack *stackA, t_stack *stackB, int *lis, int mid_lis)
{
	int		i;
	int		j;
	t_node	*node;

	i = 0;
	j = 0;
	while (i++ < stackA->size + stackB->size)
	{
		node = stackA->top;
		if (lis[j] == node->value)
		{
			write(1, "ra\n", 3);
			rotate_stack(stackA);
			j++;
		}
		else
		{
			write(1, "pb\n", 3);
			push_stack(stackA, stackB);
			split_stack_mid_lis(stackA, stackB, mid_lis);
		}
	}
	return ;
}

int	a_to_b(t_stack *stackA, t_stack *stackB)
{
	int	*lis;
	int	mid_lis;

	lis = malloc(sizeof(int) * stackA->size);
	if (!lis)
		return (1);
	if (find_lis(stackA, lis, &mid_lis))
	{
		free(lis);
		return (1);
	}
	split_stack_lis(stackA, stackB, lis, mid_lis);
	free(lis);
	return (0);
}
