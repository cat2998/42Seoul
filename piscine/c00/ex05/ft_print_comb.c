/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:41:19 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/10 12:13:51 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int *arr);

void	ft_print_comb(void)
{
	int	comb[3];
	int	i;
	int	j;
	int	z;

	i = 0;
	while (i <= 7)
	{
		comb[0] = i + '0';
		j = i + 1;
		while (j <= 8)
		{
			comb[1] = j + '0';
			z = j + 1;
			while (z <= 9)
			{
				comb[2] = z + '0';
				ft_print(comb);
				z++;
			}
			j++;
		}
		i++;
	}
}

void	ft_print(int *arr)
{
	write(1, &arr[0], 1);
	write(1, &arr[1], 1);
	write(1, &arr[2], 1);
	if (!(arr[0] == 55))
		write(1, ", ", 2);
}
