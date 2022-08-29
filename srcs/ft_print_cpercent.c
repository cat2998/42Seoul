/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cpercent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:39:05 by jgwon             #+#    #+#             */
/*   Updated: 2022/08/29 20:02:57 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_czerospace(t_info *info)
{
	int	cnt;

	cnt = 1;
	while (info->width > cnt)
	{
		if (info->zero == 1 && info->minus != 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		cnt++;
	}
	return (cnt - 1);
}

int	ft_print_cpercent(char c, t_info *info)
{
	int	cnt;

	cnt = 0;
	if (info->minus == 1)
	{
		write(1, &c, 1);
		cnt++;
		cnt += ft_print_czerospace(info);
	}
	else
	{
		cnt += ft_print_czerospace(info);
		write(1, &c, 1);
		cnt++;
	}
	return (cnt);
}
