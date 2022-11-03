/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:52:40 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/03 22:57:04 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lower_bound(int *list, int size, int target)
{
	int	start;
	int	end;
	int	mid;

	start = 0;
	end = size - 1;
	while (end > start)
	{
		mid = (start + end) / 2;
		if (list[mid] >= target)
			end = mid;
		else
			start = mid + 1;
	}
	return (end);
}

int	find_lis_size(int *lis, int *index, t_stack *stack)
{
	int		i;
	int		size;
	t_node	*node;

	i = 0;
	size = 0;
	node = stack->top;
	while (i < stack->size)
	{
		if (size == 0 || lis[size - 1] < node->value)
		{
			index[i++] = size;
			lis[size++] = node->value;
		}
		else
		{
			index[i++] = lower_bound(lis, size, node->value);
			lis[lower_bound(lis, size, node->value)] = node->value;
		}
		node = node->next;
	}
	return (size);
}

void	make_lis(int *lis, int size, int *index, t_stack *stack)
{
	int		i;
	int		find;
	t_node	*node;

	i = stack->size - 1;
	find = size - 1;
	node = stack->bottom;
	while (i >= 0)
	{
		if (index[i] == find)
		{
			lis[find] = node->value;
			find--;
		}
		node = node->prev;
		i--;
	}
	return ;
}

int	find_lis(t_stack *stack, int *lis, int *mid_lis)
{
	int	*index;
	int	lis_size;

	index = malloc(sizeof(int) * stack->size);
	if (!index)
		return (1);
	lis_size = find_lis_size(lis, index, stack);
	make_lis(lis, lis_size, index, stack);
	*mid_lis = lis[lis_size / 2];
	free(index);
	return (0);
}
