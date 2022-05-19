/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 20:16:10 by jgwon             #+#    #+#             */
/*   Updated: 2022/05/19 19:51:47 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(int n);
int	ft_abs(int n);

char	*ft_itoa(int n)
{
	int		size;
	int		minus;
	char	*str;

	minus = 1;
	if (n < 0)
		minus *= -1;
	size = ft_size(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	str[size--] = '\0';
	while (size >= 0)
	{
		str[size] = ft_abs(n % 10) + 48;
		n = n / 10;
		size--;
	}
	if (minus == -1)
		str[0] = '-';
	return (str);
}

int	ft_size(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}
