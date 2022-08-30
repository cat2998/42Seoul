/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:43:05 by jgwon             #+#    #+#             */
/*   Updated: 2022/08/30 19:46:06 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_plusspace(t_info *info)
{
	int	cnt;

	cnt = 0;
	if (info->sign < 0)
	{
		write(1, "-", 1);
		cnt++;
	}
	else if (info->sign > 0 && info->plus == 1)
	{
		write(1, "+", 1);
		cnt++;
	}
	else if (info->sign > 0 && info->space == 1)
	{
		write(1, " ", 1);
		cnt++;
	}
	return (cnt);
}

int	ft_print_prec(unsigned long n, t_info *info)
{
	int	cnt;
	int	len;

	cnt = 0;
	len = ft_len(n, info);
	if (info->prec_n > len)
	{
		info->prec_n = info->prec_n - len;
		while (info->prec_n > cnt)
		{
			write(1, "0", 1);
			cnt++;
		}
	}
	return (cnt);
}

int	ft_print_width(int cnt, unsigned long n, t_info *info)
{
	int	count;
	int	tmp;

	if (info->minus != 1)
	{
		if (info->prec == 1 || (info->prec != 1 && info->zero != 1))
		{
			count = ft_len(n, info);
			tmp = info->prec_n - count;
			while (tmp-- > 0)
				count++;
			count = width_check(count, info);
			info->width = info->width - count;
		}
	}
	if (!(info->minus != 1 && info->prec != 1 && info->zero == 1))
	{
		while (info->width > cnt)
		{
			write(1, " ", 1);
			cnt++;
		}
	}
	return (cnt);
}

int	ft_print_zero(int cnt, unsigned long n, t_info *info)
{
	int	len;

	len = ft_len(n, info);
	if (info->prec == 0 && info->zero == 1)
	{
		info->width = info->width - len;
		while (info->width > cnt)
		{
			write(1, "0", 1);
			cnt++;
		}
	}
	return (cnt);
}

int	ft_print_di(int d, t_info *info)
{
	int				cnt;
	unsigned int	n;

	cnt = 0;
	n = sign_check(d, info);
	if (info->prec == 1 && info->prec_n == 0 && d == 0)
		return (ft_print_none(info));
	if (info->minus == 1)
	{
		cnt += ft_print_plusspace(info);
		cnt += ft_print_prec(n, info);
		cnt += ft_putnbr(n, info);
		cnt = ft_print_width(cnt, n, info);
	}
	else
	{
		cnt = ft_print_width(cnt, n, info);
		cnt += ft_print_plusspace(info);
		cnt = ft_print_zero(cnt, n, info);
		cnt += ft_print_prec(n, info);
		cnt += ft_putnbr(n, info);
	}
	return (cnt);
}
