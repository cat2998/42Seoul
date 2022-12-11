/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:16:03 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/10 12:25:56 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char *arr);

void	ft_print_comb2(void)
{
	char	arr[5];
	int		i;

	i = 0001;
	while (i <= 9899)
	{
		arr[0] = i / 1000 + '0';
		arr[1] = i / 100 % 10 + '0';
		arr[3] = i / 10 % 10 + '0';
		arr[4] = i % 1000 % 100 % 10 + '0';
		arr[2] = 32;
		if (arr[0] < arr[3] || (arr[0] == arr[3] && arr[1] < arr[4]))
			ft_print(arr);
		i++;
	}
}

void	ft_print(char *arr)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		write(1, &arr[i++], 1);
	}
	if (!(arr[0] == '9' && arr[1] == '8'))
		write(1, ", ", 2);
}
