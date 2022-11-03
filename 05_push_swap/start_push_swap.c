/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:49:02 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/03 22:57:08 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_result(char *split, unsigned int *result)
{
	int	i;
	int	minus;

	i = 0;
	minus = 0;
	while (split[i] != '\0')
	{
		if (i == 0 && split[i] == '-' && split[i + 1] != '\0')
			minus = -1;
		else if ('0' <= split[i] && split[i] <= '9')
		{
			*result = *result * 10;
			*result = *result + split[i] - '0';
		}
		else if (!(i == 0 && split[i] == '+' && split[i + 1] != '\0'))
			return (1);
		if (*result > 2147483647 && minus == 0)
			return (1);
		if (*result > 2147483648 && minus == -1)
			return (1);
		i++;
	}
	if (minus == -1)
		*result = *result * minus;
	return (0);
}

int	check_error(char *split, t_stack *stack)
{
	unsigned int	result;
	t_node			*node;

	result = 0;
	if (get_result(split, &result))
		return (1);
	node = malloc(sizeof(t_node) * 1);
	if (!node)
		return (1);
	init_node(node);
	node->value = result;
	if (find_node(stack, node))
	{
		free(node);
		return (1);
	}
	push_node(stack, node);
	return (0);
}

int	into_stack(t_stack *stack, char *argv)
{
	int		i;
	char	**split;

	split = ft_split(argv, ' ');
	i = 0;
	if (split != 0 && split[i] == 0)
	{
		ft_split_all_free(split);
		return (1);
	}
	while (split != 0 && split[i] != 0)
		i++;
	while (split != 0 && --i >= 0)
	{
		if (check_error(split[i], stack))
		{
			ft_split_all_free(split);
			return (1);
		}
	}
	ft_split_all_free(split);
	return (0);
}

int	is_sort_stack(t_stack *stack)
{
	if (stack->size > 5 && is_reverse_sort(stack, stack->bottom))
	{
		swap_stack(stack);
		write(1, "sa\n", 3);
	}
	if (is_sort(stack, stack->top))
		return (1);
	return (0);
}

void	push_swap(t_stack *stackA, t_stack *stackB, char *argv[], int argc)
{
	while (argc > 1)
	{
		if (into_stack(stackA, argv[argc - 1]))
		{
			write(2, "Error\n", 6);
			return ;
		}
		argc--;
	}
	if (stackA->size < 2 || is_sort_stack(stackA))
		return ;
	if (stackA->size < 6)
		small_sort_stack(stackA, stackB);
	else
	{
		if (a_to_b(stackA, stackB))
			return ;
	}
	while (stackB->size > 0)
		b_to_a(stackA, stackB);
	sort_stack(stackA);
	return ;
}
