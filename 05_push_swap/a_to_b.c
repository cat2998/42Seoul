/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:15:11 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/02 20:07:09 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_stack_lis(t_stack *stackA, t_stack *stackB, int *lis)
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
		}
	}
	return ;
}

int	a_to_b(t_stack *stackA, t_stack *stackB)
{
	int	*lis;

	lis = malloc(sizeof(int) * stackA->size);
	if (!lis)
		return (1);
	if (find_lis(stackA, lis))
	{
		free(lis);
		return (1);
	}
	split_stack_lis(stackA, stackB, lis);
	free(lis);
	return (0);
}
