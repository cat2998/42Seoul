

#include "push_swap.h"
#include <stdio.h>
t_node  *find_second_min_node(t_stack *stack)
{
    int     i;
    t_node  *node;
    t_node  *min_node;
    t_node  *second_min_node;

    i = 0;
    min_node = find_min_node(stack);
    if (min_node->value == stack->top->value)
    {
        second_min_node = stack->top->next;
        node = stack->top->next;
    }
    else
    {
        second_min_node = stack->top;
        node = stack->top;
    }
    while (i < stack->size)
    {
        if (min_node->value != node->value)
        {
            if (min_node->value < second_min_node->value && second_min_node->value > node->value)
                second_min_node = node;
        }
        node = node->next;
        i++;
    }
    return (second_min_node);
}

void    three_sort_stack(t_stack *stack)
{
    if (stack->top->value < stack->bottom->value)
	{
		swap_stack(stack);
		write(1, "sa\n", 3);
	}
	while (stack->top->value > stack->bottom->value)
	{
		if (is_sort(stack, stack->top))
			return ;
		reverse_rotate_stack(stack);
		write(1, "rra\n", 4);
	}
	return ;
}

void    five_sort_stack(t_stack *stackA, t_stack *stackB)
{
    int     i;
    t_node  *second_min;
    t_node  *node;

    second_min = find_second_min_node(stackA);
	i = 0;
	while (i < stackA->size + stackB->size)
	{
		node = stackA->top;
		if (second_min->value < node->value)
		{
			write(1, "ra\n", 3);
			rotate_stack(stackA);
		}
		else
		{
			write(1, "pb\n", 3);
			push_stack(stackA, stackB);
		}
        i++;
	}
	return ;
}

void	small_sort_stack(t_stack *stackA, t_stack *stackB)
{
    if (stackA->size == 3)
    {
        three_sort_stack(stackA);
        return ;
    }
    else if (stackA->size < 6)
    {
        five_sort_stack(stackA, stackB);
        return ;
    }
	return ;
}

void	sort_stack(t_stack *stack)
{
	int		idx;
	int		r_idx;

	idx = find_min_node_idx(stack);
	r_idx = stack->size - idx;
	if (idx < r_idx)
	{
		while (idx-- > 0)
		{
			rotate_stack(stack);
			write(1, "ra\n", 3);
		}
	}
	else
	{
		while (r_idx-- > 0)
		{
			reverse_rotate_stack(stack);
			write(1, "rra\n", 4);
		}
	}
	return ;
}
