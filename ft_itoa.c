/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 20:16:10 by jgwon             #+#    #+#             */
/*   Updated: 2022/05/15 21:39:19 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(int n);

char	*ft_itoa(int n)
{
	int		size;
	char	*str;

	if (n == -2147483648)
	{

	}
	size = ft_size(n) + 1;
	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (0);
	str[size - 1] = '\0';
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
		while (size > 2)
		{
			str[size - 2] = n % 10 + 48;
			n = n / 10;
			size--;
		}
	}
	else
	{
		while (size > 1)
		{
			str[size - 2] = n % 10 + 48;
			n = n / 10;
			size--;
		}
	}
	return (str);
}

int	ft_size(int n)
{
	int count;

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

#include <stdio.h>
int main(void)
{
	printf("%s\n", ft_itoa(00));
	printf("%s\n", ft_itoa(+2147483647));
	printf("%s\n", ft_itoa(-217));
}
