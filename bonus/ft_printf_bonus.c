/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:08:38 by jgwon             #+#    #+#             */
/*   Updated: 2022/08/29 21:12:24 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_format_info_print(va_list ap, t_info *info)
{
	int	cnt;

	cnt = 0;
	if (info->type == 'c')
		cnt = ft_print_cpercent((char)va_arg(ap, int), info);
	else if (info->type == '%')
		cnt = ft_print_cpercent('%', info);
	else if (info->type == 's')
		cnt = ft_print_s(va_arg(ap, char *), info);
	else if (info->type == 'p')
		cnt = ft_print_uxp(va_arg(ap, unsigned long long), info);
	else if (info->type == 'd' || info->type == 'i')
		cnt = ft_print_di(va_arg(ap, int), info);
	else if (info->type == 'u' || info->type == 'x' || info->type == 'X')
		cnt = ft_print_uxp(va_arg(ap, unsigned int), info);
	return (cnt);
}

void	ft_info_check(const char *format, t_info *info)
{
	if (*format == '-' && info->prec == 0)
		info->minus = 1;
	else if (*format == '+')
		info->plus = 1;
	else if (*format == ' ')
		info->space = 1;
	else if (*format == '0' && info->width == 0 && info->prec == 0)
		info->zero = 1;
	else if (*format == '#')
		info->sharp = 1;
	else if (*format == '.')
		info->prec = 1;
	else
	{
		if (info->prec == 1)
			info->prec_n = info->prec_n * 10 + (*format - 48);
		else
			info->width = info->width * 10 + (*format - 48);
	}
	return ;
}

const char	*ft_info(const char *format, t_info *info)
{
	while (*format != 'c' && *format != 's' && *format != 'p' \
		&& *format != 'd' && *format != 'i' && *format != 'u' \
		&& *format != 'x' && *format != 'X' && *format != '%')
	{
		ft_info_check(format, info);
		format++;
	}
	info->type = *format;
	return (format);
}

int	ft_format_printf(va_list ap, const char *format)
{
	int		cnt;
	t_info	*info;

	cnt = 0;
	info = malloc(sizeof(t_info) * 1);
	if (!info)
		return (0);
	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			init_info(info);
			format = ft_info(format, info);
			cnt += ft_format_info_print(ap, info);
		}
		else if (*format != '%')
		{
			write(1, format, 1);
			cnt++;
		}
		format++;
	}
	free(info);
	return (cnt);
}

int	ft_printf(const char *format, ...)
{
	int		cnt;
	va_list	ap;

	va_start(ap, format);
	cnt = ft_format_printf(ap, format);
	va_end(ap);
	return (cnt);
}
