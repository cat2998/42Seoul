/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:15:24 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/25 14:42:08 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_print(char *arr, int i);

void	ft_show_tab(struct s_stock_str *par)
{
	int		i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
	return ;
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	return ;
}

void	ft_putnbr(int nb)
{
	int		i;
	char	arr[10];

	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
		ft_putnbr(nb);
	}
	else
	{
		i = 9;
		while (nb / 10 != 0)
		{
			arr[i--] = nb % 10 + '0';
			nb /= 10;
		}
		arr[i] = nb + '0';
		ft_print(arr, i);
	}
}

void	ft_print(char *arr, int i)
{
	while (i < 10)
	{
		write(1, &arr[i++], 1);
	}
}
