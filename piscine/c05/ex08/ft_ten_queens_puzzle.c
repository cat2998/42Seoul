/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:50 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/19 20:40:25 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_queens(int *arr, int col);
int		ft_check(int *arr, int col);
int		ft_abs(int a);
void	ft_print(int *arr);

int	ft_ten_queens_puzzle(void)
{
	int	cnt;
	int	arr[10];

	cnt = ft_queens(arr, -1);
	return (cnt);
}

int	ft_queens(int *arr, int col)
{
	int	i;
	int	cnt;

	cnt = 0;
	if (ft_check(arr, col))
	{
		if (col == 9)
		{
			ft_print(arr);
			write(1, "\n", 1);
			return (1);
		}
		else
		{
			i = 0;
			while (i < 10)
			{
				arr[col + 1] = i;
				cnt += ft_queens(arr, col + 1);
				i++;
			}
		}
	}
	return (cnt);
}

int	ft_check(int *arr, int col)
{
	int	k;
	int	flag;

	k = 0;
	flag = 1;
	while (k < col)
	{
		if (arr[col] == arr[k] || ft_abs(arr[col] - arr[k]) == ft_abs(col - k))
			flag = 0;
		k++;
	}
	return (flag);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

void	ft_print(int *arr)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
		i++;
	}
	return ;
}
