/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:29:24 by jgwon             #+#    #+#             */
/*   Updated: 2022/10/29 17:03:22 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

void    init_stack(t_stack *s);
void	push_node(t_stack *stackA, t_node *node);
void	swap_stack(t_stack *stack);
void	push_stack(t_stack *stackA, t_stack *stackB);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);

void	print_stack(t_stack *stackA);

#endif