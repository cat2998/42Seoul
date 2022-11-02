/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:28:11 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/02 21:57:56 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_node_info(t_stack *stackA, t_stack *stackB, int position)
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;

	ra = find_dest(stackA, stackB);
	rra = stackA->size - ra;
	rb = position;
	rrb = stackB->size - rb;
	stackB->top->info[0] = ra;
	stackB->top->info[1] = rb;
	stackB->top->info[2] = rra;
	stackB->top->info[3] = rrb;
	return ;
}

int	find_optimum(t_node *node)
{
	int	i;
	int	key;
	int	values[4];

	values[0] = ft_max(node->info[0], node->info[1]);
	values[1] = node->info[0] + node->info[3];
	values[2] = node->info[2] + node->info[1];
	values[3] = ft_max(node->info[2], node->info[3]);
	i = 0;
	key = i;
	while (i < 4)
	{
		if (values[key] > values[i])
			key = i;
		i++;
	}
	node->info[6] = key;
	return (values[key]);
}

void	execute(t_stack *stackA, t_stack *stackB, t_node *node)
{
	while (node->info[0]-- > 0)
	{
		rotate_stack(stackA);
		write(1, "ra\n", 3);
	}
	while (node->info[1]-- > 0)
	{
		rotate_stack(stackB);
		write(1, "rb\n", 3);
	}
	while (node->info[2]-- > 0)
	{
		reverse_rotate_stack(stackA);
		write(1, "rra\n", 4);
	}
	while (node->info[3]-- > 0)
	{
		reverse_rotate_stack(stackB);
		write(1, "rrb\n", 4);
	}
	return ;
}

void	execute2(t_stack *stackA, t_stack *stackB, t_node *node)
{
	while (node->info[4]-- > 0)
	{
		rotate_stack(stackA);
		rotate_stack(stackB);
		write(1, "rr\n", 3);
	}
	while (node->info[5]-- > 0)
	{
		reverse_rotate_stack(stackA);
		reverse_rotate_stack(stackB);
		write(1, "rrr\n", 4);
	}
	push_stack(stackB, stackA);
	write(1, "pa\n", 3);
	return ;
}

void	b_to_a(t_stack *stackA, t_stack *stackB)
{
	int		i;
	int		tmp;
	int		optimum;
	t_node	*optimal_node;

	i = 0;
	tmp = stackA->size + stackB->size;
	while (i < stackB->size)
	{
		set_node_info(stackA, stackB, i);
		optimum = find_optimum(stackB->top);
		if (tmp > optimum)
		{
			tmp = optimum;
			optimal_node = stackB->top;
		}
		rotate_stack(stackB);
		i++;
	}
	set_node_key_info(optimal_node);
	execute(stackA, stackB, optimal_node);
	execute2(stackA, stackB, optimal_node);
	return ;
}
