/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:31:46 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/10 12:34:53 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_comb(int depth, int next, int n, int *arr);
void	ft_print(int n, int *arr);

void	ft_print_combn(int n)
{
	int	arr[9];

	ft_comb(0, 0, n, arr);
}

void	ft_comb(int depth, int next, int n, int *arr)
{
	int	i;

	if (depth == n)
	{
		ft_print(n, arr);
		return ;
	}
	i = next;
	while (i < 10)
	{
		arr[depth] = i + '0';
		ft_comb(depth + 1, i + 1, n, arr);
		i++;
	}
}

void	ft_print(int n, int *arr)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &arr[i++], 1);
	}
	if (arr[0] != (10 - n) + '0')
		write(1, ", ", 2);
}
