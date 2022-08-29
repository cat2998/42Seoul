/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uxXp_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:44:03 by jgwon             #+#    #+#             */
/*   Updated: 2022/08/29 21:12:22 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_sharp(unsigned long long d, t_info *info)
{
	int	cnt;

	cnt = 0;
	if (info->type == 'x' && info->sharp == 1 && d != 0)
	{
		write(1, "0", 1);
		write(1, "x", 1);
		cnt += 2;
	}
	else if (info->type == 'X' && info->sharp == 1 && d != 0)
	{
		write(1, "0", 1);
		write(1, "X", 1);
		cnt += 2;
	}
	else if (info->type == 'p')
	{
		write(1, "0", 1);
		write(1, "x", 1);
		cnt += 2;
	}
	return (cnt);
}

int	ft_print_uxp(unsigned long long d, t_info *info)
{
	int	cnt;

	cnt = 0;
	base_check(info);
	if (info->prec == 1 && info->prec_n == 0 && d == 0)
		return (ft_print_none(info));
	if (info->minus == 1)
	{
		cnt += ft_print_sharp(d, info);
		cnt += ft_print_prec(d, info);
		cnt += ft_putnbr(d, info);
		cnt = ft_print_width(cnt, d, info);
	}
	else
	{
		cnt = ft_print_width(cnt, d, info);
		cnt += ft_print_sharp(d, info);
		cnt = ft_print_zero(cnt, d, info);
		cnt += ft_print_prec(d, info);
		cnt += ft_putnbr(d, info);
	}
	return (cnt);
}
