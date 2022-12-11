/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:14:09 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/16 15:22:08 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char *arr, int i);

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
