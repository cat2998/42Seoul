/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:37:37 by jgwon             #+#    #+#             */
/*   Updated: 2022/08/29 20:35:37 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->minus = 0;
	info->plus = 0;
	info->space = 0;
	info->zero = 0;
	info->sharp = 0;
	info->width = 0;
	info->prec = 0;
	info->prec_n = 0;
	info->sign = 1;
	info->base = 10;
}

void	base_check(t_info *info)
{
	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		info->base = 16;
	return ;
}

unsigned int	sign_check(int d, t_info *info)
{
	unsigned int	n;

	if (d < 0)
	{
		info->sign = -1;
		n = -d;
	}
	else
		n = d;
	return (n);
}

int	width_check(int count, t_info *info)
{
	if (info->type == 'd' || info->type == 'i')
	{
		if (info->sign < 0 || \
			(info->sign > 0 && (info->plus == 1 || info->space == 1)))
			count++;
	}
	if (info->type == 'p' || \
		((info->type == 'x' || info->type == 'X') && info->sharp == 1))
		count += 2;
	return (count);
}

int	ft_len(unsigned long long n, t_info *info)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n = n / info->base;
		len++;
	}
	return (len);
}
