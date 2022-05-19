/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:45:32 by jgwon             #+#    #+#             */
/*   Updated: 2022/05/19 19:30:59 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_space(const char *str, int *str_i);
int		ft_minus(const char *str, int *str_i);

int	ft_atoi(const char *str)
{
	int			i;
	int			minus;
	long int	result;

	i = 0;
	result = 0;
	ft_space(str, &i);
	minus = ft_minus(str, &i);
	while ('0' <= str[i] && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		if (result > 2147483647 && minus == 1)
			return (-1);
		if (result > 2147483648 && minus == -1)
			return (0);
		i++;
	}
	result *= minus;
	return (result);
}

void	ft_space(const char *str, int *str_i)
{
	int	i;

	i = 0;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == ' '
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
	{
		i++;
	}
	*str_i = i;
}

int	ft_minus(const char *str, int *str_i)
{
	int	i;
	int	minus;

	i = *str_i;
	minus = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	*str_i = i;
	return (minus);
}
