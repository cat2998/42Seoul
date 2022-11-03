/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:15:11 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/04 01:05:38 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_lis(long long *lis, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		lis[i] = 2147483648;
		i++;
	}
	return ;
}

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

void	split_stack_lis(t_stack *stackA, t_stack *stackB, \
						long long *lis, int mid_lis)
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
	int			mid_lis;
	long long	*lis;

	lis = malloc(sizeof(long long) * stackA->size);
	if (!lis)
		return (1);
	init_lis(lis, stackA->size);
	if (find_lis(stackA, lis, &mid_lis))
	{
		free(lis);
		return (1);
	}
	split_stack_lis(stackA, stackB, lis, mid_lis);
	free(lis);
	return (0);
}
