/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:17:07 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/03 22:57:02 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_dest(t_stack *stackA, t_stack *stackB)
{
	int		i;
	int		j;
	t_node	*node;

	i = 0;
	while (i < stackA->size)
	{
		push_stack(stackB, stackA);
		node = find_min_node(stackA);
		if (is_sort(stackA, node))
		{
			j = 0;
			push_stack(stackA, stackB);
			while (j++ < i)
				reverse_rotate_stack(stackA);
			return (i);
		}
		else
		{
			push_stack(stackA, stackB);
			rotate_stack(stackA);
		}
		i++;
	}
	return (0);
}

void	set_node_key_info_detail(t_node *node, int a, int b, int c)
{
	node->info[c] = ft_min(node->info[a], node->info[b]);
	node->info[a] = node->info[a] - node->info[c];
	node->info[b] = node->info[b] - node->info[c];
	return ;
}

void	set_node_key_info_detail2(t_node *node, int a, int b)
{
	node->info[a] = 0;
	node->info[b] = 0;
	return ;
}

void	set_node_key_info(t_node *node)
{
	if (node->info[6] == 0)
	{
		set_node_key_info_detail(node, 0, 1, 4);
		set_node_key_info_detail2(node, 2, 3);
	}
	else if (node->info[6] == 1)
		set_node_key_info_detail2(node, 1, 2);
	else if (node->info[6] == 2)
		set_node_key_info_detail2(node, 0, 3);
	else if (node->info[6] == 3)
	{
		set_node_key_info_detail(node, 2, 3, 5);
		set_node_key_info_detail2(node, 0, 1);
	}
	return ;
}
