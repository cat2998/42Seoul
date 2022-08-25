/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:08:38 by jgwon             #+#    #+#             */
/*   Updated: 2022/08/24 22:44:46 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

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

void	ft_check_flag(const char *format, t_info *info)
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
			info->prec_n = info->prec_n * 10 + (*format - 48);
		else
			info->width = info->width * 10 + (*format - 48);
	}
}

const char *ft_info(const char *format, t_info *info)
{
	while (*format != 'c' && *format != 's' && *format != 'p' \
		&& *format != 'd' && *format != 'i' && *format != 'u' \
		&& *format != 'x' && *format != 'X' && *format != '%')
	{
		ft_check_flag(format, info);
		format++;
	}
	info->type = *format;
	return format;
}

int	print_none(t_info *info, char c)
{
	if (info->prec == -1 && c == 0)
	{
		write(1, "None", 4);
		return (1);
	}
	return (0);
}

int	ft_print_char(va_list *ap, t_info *info)
{
	int	cnt;
	char c;

	cnt = 0;
	c = (char)va_arg(*ap, int);
	if (print_none(info, c))
		return (1);
	else if (info->minus == 1)
	{
		write(1, &c, 1);
		cnt++;
		info->width--;
		while (info->width > 0)
		{
			write(1, " ", 1);
			cnt++;
			info->width--;
		}
		return (cnt);
	}
	else if (info->zero == 1)
	{
		while (info->width >= 0)
		{
			if (info->width <= 1)
			{
				write(1, &c, 1);
				cnt++;
				return (cnt);
			}
			write(1, "0", 1);
			cnt++;
			info->width--;
		}
	}
	else
	{
		while (info->width >= 0)
		{
			if (info->width <= 1)
			{
				write(1, &c, 1);
				cnt++;
				return (cnt);
			}
			write(1, " ", 1);
			cnt++;
			info->width--;
		}
	}
	return (cnt);
}

int	ft_print_string(va_list *ap, t_info *info)
{
	return (0);
}

int	ft_print_pointer(va_list *ap, t_info *info)
{
	return (0);
}

int	ft_print_int(va_list *ap, t_info *info)
{
	return (0);
}

int	ft_print_int2(va_list *ap, t_info *info)
{
	return (0);
}

int	ft_print_unsigned_int(va_list *ap, t_info *info)
{
	return (0);
}

int	ft_print_x(va_list *ap, t_info *info)
{
	return (0);
}

int	ft_print_X(va_list *ap, t_info *info)
{
	return (0);
}

int	ft_print_percent(va_list *ap, t_info *info)
{
	int	cnt;

	cnt = 0;
	if (info->minus == 1)
	{
		write(1, "%", 1);
		cnt++;
		info->width--;
		while (info->width > 0)
		{
			write(1, " ", 1);
			cnt++;
			info->width--;
		}
		return (cnt);
	}
	else if (info->zero == 1)
	{
		while (info->width >= 0)
		{
			if (info->width <= 1)
			{
				write(1, "%", 1);
				cnt++;
				return (cnt);
			}
			write(1, "0", 1);
			cnt++;
			info->width--;
		}
	}
	else
	{
		while (info->width >= 0)
		{
			if (info->width <= 1)
			{
				write(1, "%", 1);
				cnt++;
				return (cnt);
			}
			write(1, " ", 1);
			cnt++;
			info->width--;
		}
	}
	return (cnt);
}

int	ft_format_info_print(va_list *ap, t_info *info)
{
	int cnt;

	if (info->type == 'c')
		cnt = ft_print_char(ap, info);
	else if (info->type == 's')
		cnt = ft_print_string(ap, info);
	else if (info->type == 'p')
		cnt = ft_print_pointer(ap, info);
	else if (info->type == 'd')
		cnt = ft_print_int(ap, info);
	else if (info->type == 'i')
		cnt = ft_print_int2(ap, info);
	else if (info->type == 'u')
		cnt = ft_print_unsigned_int(ap, info);
	else if (info->type == 'x')
		cnt = ft_print_x(ap, info);
	else if (info->type == 'X')
		cnt = ft_print_X(ap, info);
	else if (info->type == '%')
		cnt = ft_print_percent(ap, info);
	return (cnt);
}

int	ft_format_printf(va_list ap, const char *format)
{
	int		cnt;
	t_info	*info;

	cnt = 0;
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
			cnt += ft_format_info_print(&ap, info);
		}
		else
		{
			write(1, format, 1);
			cnt++;
		}
		format++;
	}
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

int main(void)
{
	printf("printf return %d\n", printf("%-04.0c|%04.c|%4c|%c|%.0c|\n", 'a', 'a', 'a', 'a', 0));
	printf("ft_printf return %d\n", ft_printf("%-04.0c|%04.c|%4c|%c|%.0c|\n", 'a', 'a', 'a', 'a', 0));
	printf("printf return %d\n", printf("%-04.0%|%04.%|%4%|%%|%.0%|\n"));
	printf("ft_printf return %d\n", ft_printf("%-04.0%|%04.%|%4%|%%|%.0%|\n"));
}