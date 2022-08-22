/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:08:38 by jgwon             #+#    #+#             */
/*   Updated: 2022/08/22 23:45:53 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct s_info
{
	int	minus;
	int	plus;
	int	space;
	int	zero;
	int	sharp;
	int	width;
	int prec;
	int prec_n;
	char	type;
}	t_info;

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
}

const char *ft_info(const char *format, t_info *info)
{
	while (*format != 'c' && *format != 's' && *format != 'p' && *format != 'd' \
		&& *format != 'i' && *format != 'u' && *format != 'x' && *format != 'X' && *format != '%')
	{
		if (*format == '-')
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
			if (info->prec == 1 && info->prec_n == 0 && *format == '0')
				info->prec = -1;
			else if (info->prec == 1)
				info->prec_n = info->prec_n * 10 + *format;
			else
				info->width = info->width * 10 + *format;
		}
		format++;
	}
	info->type = *format;
	return format;
}

int	ft_format_printf(va_list ap, const char *format)
{
	// int	a;
	t_info	*info;

	info = malloc(sizeof(t_info) * 1);
	if (!info)
		return (0);
	while (*format != 0)
	{
		if (*format == '%')
		{
			format++;
			init_info(info);
			format = ft_info(format, info);
		}
		else
		{
			printf("%c", *format);
		}
		format++;
	}

	// for (int i = 0; i < 3; i++)
	// {
	// 	a = va_arg(ap, int);
	// 	printf("%d\n", a);
	// }
	return 0;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	ft_format_printf(ap, format);
	va_end(ap);

	return 0;
}

int main(void)
{
	ft_printf("Hello%+100dWorld%d!!!%d", 10, 20, 30);
}