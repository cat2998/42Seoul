/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:08:38 by jgwon             #+#    #+#             */
/*   Updated: 2022/08/25 23:55:40 by jgwon            ###   ########.fr       */
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

int	ft_print_none(t_info *info, char c)
{
	if (info->prec == -1 && c == 0)
	{
		write(1, "None", 4);
		return (1);
	}
	return (0);
}

void	ft_putchar(char c, int *cnt, t_info *info)
{
	write(1, &c, 1);
	*cnt += 1;
	info->width--;

	return ;
}

int	ft_print_c(va_list *ap, t_info *info)
{
	int	cnt;
	char c;

	cnt = 0;
	c = (char)va_arg(*ap, int);
	if (ft_print_none(info, c))
		return (1);
	else if (info->minus == 1)
	{
		ft_putchar(c, &cnt, info);
		while (info->width > 0)
			ft_putchar(' ', &cnt, info);
		return (cnt);
	}
	else if (info->zero == 1)
	{
		while (info->width >= 0)
		{
			if (info->width <= 1)
			{
				ft_putchar(c, &cnt, info);
				return (cnt);
			}
			ft_putchar('0', &cnt, info);
		}
	}
	else
	{
		while (info->width >= 0)
		{
			if (info->width <= 1)
			{
				ft_putchar(c, &cnt, info);
				return (cnt);
			}
			ft_putchar(' ', &cnt, info);
		}
	}
	return (cnt);
}

int	ft_print_s(va_list *ap, t_info *info)
{
	return (0);
}

int	ft_print_p(va_list *ap, t_info *info)
{
	return (0);
}

int	ft_len(int c)
{
	int n;

	if (c == 0)
		return (1);
	n = 0;
	while (c != 0)
	{
		c = c / 10;
		n++;
	}
	return (n);
}

void	ft_putnbr(int n, int *cnt, t_info *info)
{
	char	str;

	if (n == -2147483648)
	{
		ft_putnbr(n / 10, cnt, info);
		ft_putchar('8', &cnt, info);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar('-', &cnt, info);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, cnt, info);
		str = n % 10 + 48;
	}
	else
		str = n + 48;
	ft_putchar(str, &cnt, info);
}

int	ft_print_d(va_list *ap, t_info *info)
{
	int	cnt;
	int c;
	int len;

	cnt = 0;
	c = va_arg(*ap, int);
	len = ft_len(c);
	if (ft_print_none(info, (char)c))
		return (1);
	// if (info->plus == 1)
	// 	ft_putchar('+', &cnt, info);
	// else if (info->space == 1)
	// 	ft_putchar(' ', &cnt, info);
	if (info->prec_n > len)
	{
		if (info->minus == 1)
		{
			if (info->plus == 1)
				ft_putchar('+', &cnt, info);
			else if (info->space == 1)
				ft_putchar(' ', &cnt, info);
			info->prec_n = info->prec_n - len;
			while (info->prec_n > 0)
			{
				ft_putchar('0', &cnt, info);
				info->prec_n--;
			}
			ft_putnbr(c, &cnt, info);
			while (info->width > 0)
				ft_putchar(' ', &cnt, info);
		}
		else
		{
			info->width = info->width - info->prec_n;
			while (info->width > 0)
			{
				if (info->plus == 1 && info->width == 1)
				{
					ft_putchar('+', &cnt, info);
					continue;
				}
				else if (info->space == 1 && info->width == 1)
				{
					ft_putchar(' ', &cnt, info);
					continue;
				}
				ft_putchar(' ', &cnt, info);
			}
			info->prec_n = info->prec_n - len;
			while (info->prec_n > 0)
			{
				ft_putchar('0', &cnt, info);
				info->prec_n--;
			}
			ft_putnbr(c, &cnt, info);
		}
	}
	else
	{
		if (info->minus == 1)
		{
			if (info->plus == 1)
				ft_putchar('+', &cnt, info);
			else if (info->space == 1)
				ft_putchar(' ', &cnt, info);
			ft_putnbr(c, &cnt, info);
			while (info->width > 0)
				ft_putchar(' ', &cnt, info);
		}
		else if (info->zero == 1)
		{
			if (info->plus == 1)
				ft_putchar('+', &cnt, info);
			else if (info->space == 1)
				ft_putchar(' ', &cnt, info);
			info->width = info->width - len;
			while (info->width > 0)
				ft_putchar('0', &cnt, info);
			ft_putnbr(c, &cnt, info);
		}
		else
		{
			info->width = info->width - len;
			while (info->width > 0)
			{
				if (info->plus == 1 && info->width == 1)
				{
					ft_putchar('+', &cnt, info);
					continue;
				}
				else if (info->space == 1 && info->width == 1)
				{
					ft_putchar(' ', &cnt, info);
					continue;
				}
				ft_putchar(' ', &cnt, info);
			}
			ft_putnbr(c, &cnt, info);
		}
	}
	return (cnt);
}

int	ft_print_i(va_list *ap, t_info *info)
{
	return (0);
}

int	ft_print_u(va_list *ap, t_info *info)
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
		ft_putchar('%', &cnt, info);
		while (info->width > 0)
			ft_putchar(' ', &cnt, info);
		return (cnt);
	}
	else if (info->zero == 1)
	{
		while (info->width >= 0)
		{
			if (info->width <= 1)
			{
				ft_putchar('%', &cnt, info);
				return (cnt);
			}
			ft_putchar('0', &cnt, info);
		}
	}
	else
	{
		while (info->width >= 0)
		{
			if (info->width <= 1)
			{
				ft_putchar('%', &cnt, info);
				return (cnt);
			}
			ft_putchar(' ', &cnt, info);
		}
	}
	return (cnt);
}

int	ft_format_info_print(va_list *ap, t_info *info)
{
	int cnt;

	if (info->type == 'c')
		cnt = ft_print_c(ap, info);
	else if (info->type == 's')
		cnt = ft_print_s(ap, info);
	else if (info->type == 'p')
		cnt = ft_print_p(ap, info);
	else if (info->type == 'd')
		cnt = ft_print_d(ap, info);
	else if (info->type == 'i')
		cnt = ft_print_i(ap, info);
	else if (info->type == 'u')
		cnt = ft_print_u(ap, info);
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
	// printf("printf return %d\n", printf("%-04.0c|%04.c|%4c|%c|%.0c|\n", 'a', 'a', 'a', 'a', 0));
	// printf("ft_printf return %d\n", ft_printf("%-04.0c|%04.c|%4c|%c|%.0c|\n", 'a', 'a', 'a', 'a', 0));
	// printf("printf return %d\n", printf("%-04.0%|%04.%|%4%|%%|%.0%|\n"));
	// printf("ft_printf return %d\n", ft_printf("%-04.0%|%04.%|%4%|%%|%.0%|\n"));
	printf("printf return %d\n", printf("%d|%4d|%+4d|%+- 4d|% 04d|%- 04.0d|% 04.3d|%-2.4d|%+6.4d|%.0d|\n", 10, 10, 10, 10, 10, 10, 10, 10, 10, 0));
	printf("ft_printf return %d\n", ft_printf("%d|%4d|%+4d|%+- 4d|% 04d|%- 04.0d|% 04.3d|%-2.4d|%+6.4d|%.0d|\n", 10, 10, 10, 10, 10, 10, 10, 10, 10, 0));

 	// int a = 1;
	// int* p;
	// p = &a;
	// printf("return: %d\n", printf("default w\n%4c|%4s|%4p|%4d|%4i|%4u|%6x|%6X|%4%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// ft_printf("return: %d\n", ft_printf("default w\n%4c|%4s|%4p|%4d|%4i|%4u|%6x|%6X|%4%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// printf("return: %d\n", printf("'-w'\n%-4c|%-4s|%-4p|%-4d|%-4i|%-4u|%-6x|%-6X|%-4%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// ft_printf("return: %d\n", ft_printf("'-w'\n%-4c|%-4s|%-4p|%-4d|%-4i|%-4u|%-6x|%-6X|%-4%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// printf("return: %d\n", printf("'-+w'\n%-+4c|%-+4s|%-+4p|%-+4d|%-+4i|%-+4u|%-+6x|%-+6X|%-+4%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// ft_printf("return: %d\n", ft_printf("'-+w'\n%-+4c|%-+4s|%-+4p|%-+4d|%-+4i|%-+4u|%-+6x|%-+6X|%-+4%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// printf("return: %d\n", printf("'- w'\n%- 4c|%- 4s|%- 4p|%- 4d|%- 4i|%- 4u|%- 6x|%- 6X|%- 4%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// ft_printf("return: %d\n", ft_printf("'- w'\n%- 4c|%- 4s|%- 4p|%- 4d|%- 4i|%- 4u|%- 6x|%- 6X|%- 4%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// printf("return: %d\n", printf("'#w'\n%#4c|%#4s|%#20p|%#4d|%#4i|%#4u|%#6x|%#6X|%#4%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// ft_printf("return: %d\n", ft_printf("'#w'\n%#4c|%#4s|%#20p|%#4d|%#4i|%#4u|%#6x|%#6X|%#4%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// printf("return: %d\n", printf("'0w'\n%04c|%04s|%020p|%04d|%04i|%04u|%06x|%06X|%04%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// ft_printf("return: %d\n", ft_printf("'0w'\n%04c|%04s|%020p|%04d|%04i|%04u|%06x|%06X|%04%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// printf("return: %d\n", printf("'0#w'\n%0#4c|%0#4s|%0#20p|%0#4d|%0#+4i|%0#4u|%0#6x|%0#6X|%0#4%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// ft_printf("return: %d\n", ft_printf("'0#w'\n%0#4c|%0#4s|%0#20p|%0#4d|%0#+4i|%0#4u|%0#6x|%0#6X|%0#4%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// printf("return: %d\n", printf("'-0w'\n%-04c|%-04s|%-020p|%-04d|%-04i|%-04u|%-06x|%-06X|%-04%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// ft_printf("return: %d\n", ft_printf("'-0w'\n%-04c|%-04s|%-020p|%-04d|%-04i|%-04u|%-06x|%-06X|%-04%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// printf("return: %d\n", printf("'.'\n%.c|%.s|%.p|%.d|%.i|%.u|%.x|%.X|%.%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// ft_printf("return: %d\n", ft_printf("'.'\n%.c|%.s|%.p|%.d|%.i|%.u|%.x|%.X|%.%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// printf("return: %d\n", printf("'w.'\n%4.c|%4.s|%20.p|%4.d|%4.i|%4.u|%6.x|%6.X|%4.%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// ft_printf("return: %d\n", ft_printf("'w.'\n%4.c|%4.s|%20.p|%4.d|%4.i|%4.u|%6.x|%6.X|%4.%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// printf("return: %d\n", printf("'0w.'\n%04.c|%04.s|%020.p|%04.d|%04.i|%04.u|%0#6.x|%0#6.X|%04.%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// ft_printf("return: %d\n", ft_printf("'0w.'\n%04.c|%04.s|%020.p|%04.d|%04.i|%04.u|%0#6.x|%0#6.X|%04.%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// printf("return: %d\n", printf("'w.n'\n%6.1c|%6.1s|%12.1p|%+6.1d|%+6.1i|%+6.1u|%#6.1x|%#6.1X|%6.1%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// ft_printf("return: %d\n", ft_printf("'w.n'\n%6.1c|%6.1s|%12.1p|%+6.1d|%+6.1i|%+6.1u|%#6.1x|%#6.1X|%6.1%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// printf("return: %d\n", printf("'w.n'\n%6.5c|%6.5s|%12.5p|%+6.5d|%+6.5i|%+6.5u|%#6.5x|%#6.5X|%6.5%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// ft_printf("return: %d\n", ft_printf("'w.n'\n%6.5c|%6.5s|%12.5p|%+6.5d|%+6.5i|%+6.5u|%#6.5x|%#6.5X|%6.5%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// printf("return: %d\n", printf("'w.-n'\n%6.-5c|%6.-5s|%12.-5p|%+6.-5d|%+6.-5i|%+6.-5u|%#6.-5x|%#6.-5X|%6.-5%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// ft_printf("return: %d\n", ft_printf("'w.-n'\n%6.-5c|%6.-5s|%12.-5p|%+6.-5d|%+6.-5i|%+6.-5u|%#6.-5x|%#6.-5X|%6.-5%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// printf("return: %d\n", printf("'0w.n'\n%06.1c|%06.1s|%012.1p|%+06.1d|%+06.1i|%+06.1u|%#06.1x|%#06.1X|%06.1%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// ft_printf("return: %d\n", ft_printf("'0w.n'\n%06.1c|%06.1s|%012.1p|%+06.1d|%+06.1i|%+06.1u|%#06.1x|%#06.1X|%06.1%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// printf("return: %d\n", printf("'0w.n'\n%06.5c|%06.5s|%012.5p|%+06.5d|%+06.5i|%+06.5u|%#06.5x|%#06.5X|%06.5%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// ft_printf("return: %d\n", ft_printf("'0w.n'\n%06.5c|%06.5s|%012.5p|%+06.5d|%+06.5i|%+06.5u|%#06.5x|%#06.5X|%06.5%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// printf("return: %d\n", printf("'w.0'\n%6.0c|%6.0s|%12.0p|%+6.0d|%+6.0i|%+6.0u|%#6.0x|%#6.0X|%6.0%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// ft_printf("return: %d\n", ft_printf("'w.0'\n%6.0c|%6.0s|%12.0p|%+6.0d|%+6.0i|%+6.0u|%#6.0x|%#6.0X|%6.0%|\n", 'a', "abc", p, -1, 2, 1, 0x16, 0x17));
	// printf("return: %d\n", printf("'w.0 0'\n%6.0c|%6.0s|%12.0p|%+6.0d|%+6.0i|%+6.0u|%#6.0x|%#6.0X|%6.0%|\n", 0, 0, 0, 0, 0, 0, 0, 0));
	// ft_printf("return: %d\n", ft_printf("'w.0 0'\n%6.0c|%6.0s|%12.0p|%+6.0d|%+6.0i|%+6.0u|%#6.0x|%#6.0X|%6.0%|\n", 0, 0, 0, 0, 0, 0, 0, 0));
}