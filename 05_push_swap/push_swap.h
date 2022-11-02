/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:29:24 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/02 20:54:57 by jgwon            ###   ########.fr       */
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

void	sort_stack(t_stack *stack);
void	free_all(t_stack *stackA, t_stack *stackB);

int		get_result(char *split, long *result);
int		check_error(char *split, t_stack *stack);
int		into_stack(t_stack *stack, char *argv);
int		is_sort_stack(t_stack *stack);
void	push_swap(t_stack *stackA, t_stack *stackB, char *argv[], int argc);

char	**ft_split(char const *s, char c);
int		ft_compare(char const *str, char c, int i);
char	**ft_split_s(char **split, char const *s, char c, int size);
void	*ft_split_free(char **split, int split_i);
void	*ft_split_all_free(char **split);

void	split_stack_lis(t_stack *stackA, t_stack *stackB, int *lis);
int		a_to_b(t_stack *stackA, t_stack *stackB);

int		lower_bound(int *list, int size, int target);
int		find_lis_size(int *lis, int *index, t_stack *stack);
void	make_lis(int *lis, int lis_size, int *index, t_stack *stack);
int		find_lis(t_stack *stack, int *lis);

void	set_node_info(t_stack *stackA, t_stack *stackB, int position);
int		find_optimum(t_node *node);
void	execute(t_stack *stackA, t_stack *stackB, t_node *node);
void	execute2(t_stack *stackA, t_stack *stackB, t_node *node);
void	b_to_a(t_stack *stackA, t_stack *stackB);

int		find_dest(t_stack *stackA, t_stack *stackB);
void	set_node_key_info_detail(t_node *node, int a, int b, int c);
void	set_node_key_info_detail2(t_node *node, int a, int b);
void	set_node_key_info(t_node *node);

void	push_node(t_stack *stack, t_node *node);
void	swap_stack(t_stack *stack);
void	push_stack(t_stack *stackA, t_stack *stackB);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);

void	init_node(t_node *node);
void	init_stack(t_stack *s);
int		find_node(t_stack *stack, t_node *node);
t_node	*find_min_node(t_stack *stack);
int		find_min_node_idx(t_stack *stack);

int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		is_sort(t_stack *stack, t_node *node);
int		is_reverse_sort(t_stack *stack, t_node *node);
char	*ft_strcpy(char const *s, int begin, int len, char *str);

#endif