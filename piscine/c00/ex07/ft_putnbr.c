/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:26:36 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/10 12:45:07 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int i, char *arr);

void	ft_putnbr(int nb)
{
	char	arr[10];
	int		i;

	if (nb >= 0)
	{
		i = 9;
		while (nb / 10 != 0)
		{
			arr[i--] = nb % 10 + '0';
			nb /= 10;
		}
		arr[i] = nb + '0';
		ft_print(i, arr);
	}
	else if (nb == -2147483648)
	{
		write(1, "-2", 2);
		ft_putnbr(147483648);
	}
	else
	{
		write(1, "-", 1);
		nb *= -1;
		ft_putnbr(nb);
	}
}

void	ft_print(int i, char *arr)
{
	while (i < 10)
	{
		write(1, &arr[i++], 1);
	}
}
