/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:45:54 by jgwon             #+#    #+#             */
/*   Updated: 2022/08/29 21:12:29 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putnbr(unsigned long long n, t_info *info)
{
	int		cnt;
	char	str;

	cnt = 0;
	if (n >= (unsigned long long)info->base)
	{
		cnt += ft_putnbr(n / info->base, info);
		str = n % info->base + 48;
	}
	else
		str = n + 48;
	if ((info->type == 'x' || info->type == 'p') && str > 57)
		str += 39;
	else if (info->type == 'X' && str > 57)
		str += 7;
	write(1, &str, 1);
	cnt++;
	return (cnt);
}

int	ft_putstrprec(char *str, t_info *info)
{
	int	cnt;

	cnt = 0;
	if (info->prec != 0)
	{
		while (str[cnt] != '\0' && info->prec_n > cnt)
		{
			write(1, &str[cnt], 1);
			cnt++;
		}
	}
	else
	{
		while (str[cnt] != '\0')
		{
			write(1, &str[cnt], 1);
			cnt++;
		}
	}
	return (cnt);
}

int	ft_print_none(t_info *info)
{
	int	cnt;

	cnt = 0;
	while (info->width > cnt)
	{
		write(1, " ", 1);
		cnt++;
	}
	return (cnt);
}
