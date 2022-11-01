/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:29:24 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/02 03:41:12 by jgwon            ###   ########.fr       */
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
	int				info[7];
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;


int *quick_sort_stack(t_stack *stack);

void    init_node(t_node *node);
void    init_stack(t_stack *s);
void	push_node(t_stack *stackA, t_node *node);
void	swap_stack(t_stack *stack);
void	push_stack(t_stack *stackA, t_stack *stackB);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);

int lower_bound(int *list, int size, int target);
int find_lis_size(int *lis, int *index, t_stack *stack);
void    make_lis(int *lis, int lis_size, int *index, t_stack *stack);
int    find_lis(t_stack *stack, int *lis);

int  find_min_node_idx(t_stack *stack);
int is_sort(t_stack *stack, t_node *node);
int is_reverse_sort(t_stack *stack, t_node *node);
void    b_to_a(t_stack *stackA,t_stack *stackB);

void	print_stack(t_stack *stackA);

char	**ft_split(char const *s, char c);
void	*ft_split_free(char **split, int split_i);

#endif