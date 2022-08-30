/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:41:11 by jgwon             #+#    #+#             */
/*   Updated: 2022/08/30 19:46:07 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_szerospace(char *str, t_info *info)
{
	int	cnt;
	int	tmp;

	cnt = 0;
	tmp = 0;
	if (info->prec != 0)
	{
		while (str[tmp] != '\0' && info->prec_n > tmp)
			tmp++;
	}
	else
	{
		while (str[tmp] != '\0')
			tmp++;
	}
	info->width = info->width - tmp;
	while (info->width > cnt)
	{
		if (info->zero == 1 && info->minus != 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		cnt++;
	}
	return (cnt);
}

int	ft_print_s(char *str, t_info *info)
{
	int	cnt;

	cnt = 0;
	if (str == 0)
		str = "(null)";
	if (info->minus == 1)
	{
		cnt += ft_putstrprec(str, info);
		cnt += ft_print_szerospace(str, info);
	}
	else
	{
		cnt += ft_print_szerospace(str, info);
		cnt += ft_putstrprec(str, info);
	}
	return (cnt);
}
