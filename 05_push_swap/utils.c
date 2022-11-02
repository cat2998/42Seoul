/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:14:49 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/02 20:10:27 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	is_sort(t_stack *stack, t_node *node)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}

int	is_reverse_sort(t_stack *stack, t_node *node)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (node->value > node->prev->value)
			return (0);
		node = node->prev;
		i++;
	}
	return (1);
}

char	*ft_strcpy(char const *s, int begin, int len, char *str)
{
	int	i;

	i = 0;
	while (i < len)
	{
		str[i] = s[begin + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
