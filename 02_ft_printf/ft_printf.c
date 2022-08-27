/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:08:38 by jgwon             #+#    #+#             */
/*   Updated: 2022/08/27 20:05:12 by jgwon            ###   ########.fr       */
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
	int sign;
	int	base;
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
	info->sign = 1;
	info->base = 10;
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
	return ;
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
	return (format);
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

int	ft_print_c_percent_zerospace(t_info *info)
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

int	ft_print_c_percent(char c, t_info *info)
{
	int	cnt;

	cnt = 0;
	// if (info->prec == -1 && c == 0)
	// 	return (ft_print_none(info));
	if (info->minus == 1)
	{
		write(1, &c, 1);
		cnt++;
		cnt += ft_print_c_percent_zerospace(info);
	}
	else
	{
		cnt += ft_print_c_percent_zerospace(info);
		write(1, &c, 1);
		cnt++;
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

int	ft_len(unsigned int n, t_info *info)
{
	int len;

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

int	ft_putnbr(unsigned int n, t_info *info)
{
	int	cnt;
	char	str;

	cnt = 0;
	if (n >= info->base)
	{
		cnt += ft_putnbr(n / info->base, info);
		str = n % info->base + 48;
	}
	else
	{
		str = n + 48;
		if (info->type == 'x' && str > 57)
			str += 39;
		else if (info->type == 'X' && str > 57)
			str += 7;
	}
	write(1, &str, 1);
	cnt++;
	return (cnt);
}

unsigned int	int_to_sizet(int d, t_info *info)
{
	unsigned int	n;

	if (d < 0)
	{
		info->sign =  -1;
		n = -d;
	}
	else
		n = d;
	return (n);
}

unsigned int	base_check(unsigned int d, t_info *info)
{
	unsigned int	n;

	if (info->type == 'x' || info->type == 'X')
		info->base = 16;
	n = d;
	return (n);
}

int	ft_print_di_plusspace(t_info *info)
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

int	ft_print_di_prec(unsigned int n, t_info *info)
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

int	ft_print_di_width(int cnt, unsigned int n, t_info *info)
{
	int count;
	int	tmp;

	if (info->minus != 1 && (info->prec == 1 || (info->prec != 1 && info->zero != 1)))
	{
		count = ft_len(n, info);
		if (info->prec_n > count)
		{
			tmp = info->prec_n - count;
			while (tmp-- > 0)
				count++;
		}
		if (info->type == 'd' || info->type == 'i')
		{
			if (info->sign < 0 || (info->sign > 0 && (info->plus == 1 || info->space == 1)))
				count++;
		}
		info->width = info->width - count;
	}
	while (info->width > cnt && !(info->minus != 1 && info->prec != 1 && info->zero == 1))
	{
		write(1, " ", 1);
		cnt++;
	}
	return (cnt);
}

int	ft_print_di_zero(int cnt, unsigned int n, t_info *info)
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
	int	cnt;
	unsigned int	n;

	cnt = 0;
	n = int_to_sizet(d, info);
	if (info->prec == -1 && d == 0)
		return (ft_print_none(info));
	if (info->minus == 1)
	{
		cnt += ft_print_di_plusspace(info);
		cnt += ft_print_di_prec(n, info);
		cnt += ft_putnbr(n, info);
		cnt = ft_print_di_width(cnt, n, info);
	}
	else
	{
		cnt = ft_print_di_width(cnt, n, info);
		cnt += ft_print_di_plusspace(info);
		cnt = ft_print_di_zero(cnt, n, info);
		cnt += ft_print_di_prec(n, info);
		cnt += ft_putnbr(n, info);
	}
	return (cnt);
}

int	ft_print_uxX(unsigned int d, t_info *info)
{
	int	cnt;
	unsigned int	n;

	cnt = 0;
	n = base_check(d, info);
	if (info->prec == -1 && d == 0)
		return (ft_print_none(info));
	if (info->minus == 1)
	{
		cnt += ft_print_di_prec(n, info);
		cnt += ft_putnbr(n, info);
		cnt = ft_print_di_width(cnt, n, info);
	}
	else
	{
		cnt = ft_print_di_width(cnt, n, info);
		cnt = ft_print_di_zero(cnt, n, info);
		cnt += ft_print_di_prec(n, info);
		cnt += ft_putnbr(n, info);
	}
	return (cnt);
}

int	ft_print_x(va_list *ap, t_info *info)
{
	return (0);
}

int	ft_print_X(va_list *ap, t_info *info)
{
	return (0);
}

int	ft_format_info_print(va_list *ap, t_info *info)
{
	int	cnt;

	cnt = 0;
	if (info->type == 'c')
		cnt = ft_print_c_percent((char)va_arg(*ap, int), info);
	else if (info->type == '%')
		cnt = ft_print_c_percent('%', info);
	else if (info->type == 's')
		cnt = ft_print_s(ap, info);
	else if (info->type == 'p')
		cnt = ft_print_p(ap, info);
	else if (info->type == 'd' || info->type == 'i')
		cnt = ft_print_di(va_arg(*ap, int), info);
	else if (info->type == 'u' || info->type == 'x' || info->type == 'X')
		cnt = ft_print_uxX(va_arg(*ap, unsigned int), info);
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

int main(void)
{
	printf("printf return %d\n", printf("[%%s]:%s|[%%11s]:%11s|[%%+- 11s]:%+- 11s|[%% 05s]:% 05s|[%%- 05.0s]:%- 05.0s|[%% 05.3s]:% 05.3s|[%%-+2.4s]:%-+2.4s|[%%+6.4s]:%+6.4s|[%%6.0s]:%6.0s|\n", "hello DH!", "hello DH!", "hello DH!", "hello DH!", "hello DH!", "hello DH!", "hello DH!", "hello DH!", "hello DH!", "hello DH!", 0));
	printf("printf return %d\n", ft_printf("[%%s]:%s|[%%11s]:%11s|[%%+- 11s]:%+- 11s|[%% 05s]:% 05s|[%%- 05.0s]:%- 05.0s|[%% 05.3s]:% 05.3s|[%%-+2.4s]:%-+2.4s|[%%+6.4s]:%+6.4s|[%%6.0s]:%6.0s|\n", "hello DH!", "hello DH!", "hello DH!", "hello DH!", "hello DH!", "hello DH!", "hello DH!", "hello DH!", "hello DH!", "hello DH!", 0));

	// printf("printf return %d\n", printf("%-04.0c|%04.c|%4c|%c|%4.0c|\n", 'a', 'a', 'a', 'a', 'a'));
	// printf("ft_printf return %d\n", ft_printf("%-04.0c|%04.c|%4c|%c|%4.0c|\n", 'a', 'a', 'a', 'a', 'a'));
	// printf("printf return %d\n", printf("%-04.0c|%04.c|%4c|%c|%4.0c|\n", 0, 0, 0, 0, 0));
	// printf("ft_printf return %d\n", ft_printf("%-04.0c|%04.c|%4c|%c|%4.0c|\n", 0, 0, 0, 0, 0));

	// printf("printf return %d\n", printf("%-04.0%|%04.%|%4%|%%|%4.0%|\n"));
	// printf("ft_printf return %d\n", ft_printf("%-04.0%|%04.%|%4%|%%|%4.0%|\n"));
	
	// printf("printf return %d\n", printf("[%%d]:%d|[%%4d]:%4d|[%%+4d]:%+4d|[%%+- 4d]:%+- 4d|[%% 05d]:% 05d|[%%- 04.0d]:%- 04.0d|[%% 04.3d]:% 04.3d|[%%-+2.4d]:%-+2.4d|[%%+6.4d]:%+6.4d|[%%6.0d]:%6.0d|%6.0d|\n", -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, 0));
	// printf("ft_printf return %d\n", ft_printf("[%%d]:%d|[%%4d]:%4d|[%%+4d]:%+4d|[%%+- 4d]:%+- 4d|[%% 05d]:% 05d|[%%- 04.0d]:%- 04.0d|[%% 04.3d]:% 04.3d|[%%-+2.4d]:%-+2.4d|[%%+6.4d]:%+6.4d|[%%6.0d]:%6.0d|%6.0d|\n", -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, -2147483647, 0));
	// printf("printf return %d\n", printf("[%%d]:%d|[%%4d]:%4d|[%%+4d]:%+4d|[%%+- 4d]:%+- 4d|[%% 05d]:% 05d|[%%- 04.0d]:%- 04.0d|[%% 04.3d]:% 04.3d|[%%-+2.4d]:%-+2.4d|[%%+6.4d]:%+6.4d|[%%6.0d]:%6.0d|%4.0d|\n", -2147483648, -2147483648, -2147483648, -2147483648, -2147483648, -2147483648, -2147483648, -2147483648, -2147483648, -2147483648, 0));
	// printf("ft_printf return %d\n", ft_printf("[%%d]:%d|[%%4d]:%4d|[%%+4d]:%+4d|[%%+- 4d]:%+- 4d|[%% 05d]:% 05d|[%%- 04.0d]:%- 04.0d|[%% 04.3d]:% 04.3d|[%%-+2.4d]:%-+2.4d|[%%+6.4d]:%+6.4d|[%%6.0d]:%6.0d|%4.0d|\n", -2147483648, -2147483648, -2147483648, -2147483648, -2147483648, -2147483648, -2147483648, -2147483648, -2147483648, -2147483648, 0));
	// printf("printf return %d\n", printf("[%%d]:%d|[%%4d]:%4d|[%%+4d]:%+4d|[%%+- 4d]:%+- 4d|[%% 05d]:% 05d|[%%- 04.0d]:%- 04.0d|[%% 04.3d]:% 04.3d|[%%-+2.4d]:%-+2.4d|[%%+6.4d]:%+6.4d|[%%6.0d]:%6.0d||\n", 10, 10, 10, 10, 10, 10, 10, 10, 10, 10));
	// printf("ft_printf return %d\n", ft_printf("[%%d]:%d|[%%4d]:%4d|[%%+4d]:%+4d|[%%+- 4d]:%+- 4d|[%% 05d]:% 05d|[%%- 04.0d]:%- 04.0d|[%% 04.3d]:% 04.3d|[%%-+2.4d]:%-+2.4d|[%%+6.4d]:%+6.4d|[%%6.0d]:%6.0d||\n", 10, 10, 10, 10, 10, 10, 10, 10, 10, 10));
	// printf("printf return %d\n", printf("[%%d]:%d|[%%4d]:%4d|[%%+4d]:%+4d|[%%+- 4d]:%+- 4d|[%% 05d]:% 05d|[%%- 04.0d]:%- 04.0d|[%% 04.3d]:% 04.3d|[%%-+2.4d]:%-+2.4d|[%%+6.4d]:%+6.4d|[%%6.0d]:%6.0d|%4.0d|\n", -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, 0));
	// printf("ft_printf return %d\n", ft_printf("[%%d]:%d|[%%4d]:%4d|[%%+4d]:%+4d|[%%+- 4d]:%+- 4d|[%% 05d]:% 05d|[%%- 04.0d]:%- 04.0d|[%% 04.3d]:% 04.3d|[%%-+2.4d]:%-+2.4d|[%%+6.4d]:%+6.4d|[%%6.0d]:%6.0d|%4.0d|\n", -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, 0));
	
	// printf("printf return %d\n", printf("[%%i]:%i|[%%4i]:%4i|[%%+4i]:%+4i|[%%+- 4i]:%+- 4i|[%% 05i]:% 05i|[%%- 04.0i]:%- 04.0i|[%% 04.3i]:% 04.3i|[%%-+2.4i]:%-+2.4i|[%%+6.4i]:%+6.4i|[%%6.0i]:%6.0i|%4.0i|\n", 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x0));
	// printf("ft_printf return %d\n", ft_printf("[%%i]:%i|[%%4i]:%4i|[%%+4i]:%+4i|[%%+- 4i]:%+- 4i|[%% 05i]:% 05i|[%%- 04.0i]:%- 04.0i|[%% 04.3i]:% 04.3i|[%%-+2.4i]:%-+2.4i|[%%+6.4i]:%+6.4i|[%%6.0i]:%6.0i|%4.0i|\n", 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x0));
	// printf("printf return %d\n", printf("[%%i]:%i|[%%4i]:%4i|[%%+4i]:%+4i|[%%+- 4i]:%+- 4i|[%% 05i]:% 05i|[%%- 04.0i]:%- 04.0i|[%% 04.3i]:% 04.3i|[%%-+2.4i]:%-+2.4i|[%%+6.4i]:%+6.4i|[%%6.0i]:%6.0i||\n", 010, 010, 010, 010, 010, 010, 010, 010, 010, 010));
	// printf("ft_printf return %d\n", ft_printf("[%%i]:%i|[%%4i]:%4i|[%%+4i]:%+4i|[%%+- 4i]:%+- 4i|[%% 05i]:% 05i|[%%- 04.0i]:%- 04.0i|[%% 04.3i]:% 04.3i|[%%-+2.4i]:%-+2.4i|[%%+6.4i]:%+6.4i|[%%6.0i]:%6.0i||\n", 010, 010, 010, 010, 010, 010, 010, 010, 010, 010));
	// printf("printf return %d\n", printf("[%%i]:%i|[%%4i]:%4i|[%%+4i]:%+4i|[%%+- 4i]:%+- 4i|[%% 05i]:% 05i|[%%- 04.0i]:%- 04.0i|[%% 04.3i]:% 04.3i|[%%-+2.4i]:%-+2.4i|[%%+6.4i]:%+6.4i|[%%6.0i]:%6.0i|%4.0i|\n", -0X1a, -0X1a, -0X1a, -0X1a, -0X1a, -0X1a, -0X1a, -0X1a, -0X1a, -0X1a, 0));
	// printf("ft_printf return %d\n", ft_printf("[%%i]:%i|[%%4i]:%4i|[%%+4i]:%+4i|[%%+- 4i]:%+- 4i|[%% 05i]:% 05i|[%%- 04.0i]:%- 04.0i|[%% 04.3i]:% 04.3i|[%%-+2.4i]:%-+2.4i|[%%+6.4i]:%+6.4i|[%%6.0i]:%6.0i|%4.0i|\n", -0X1a, -0X1a, -0X1a, -0X1a, -0X1a, -0X1a, -0X1a, -0X1a, -0X1a, -0X1a, 0));
	
	// printf("printf return %d\n", printf("[%%u]:%u|[%%4u]:%4u|[%%+4u]:%+4u|[%%+- 4u]:%+- 4u|[%% 05u]:% 05u|[%%- 04.0u]:%- 04.0u|[%% 04.3u]:% 04.3u|[%%-+2.4u]:%-+2.4u|[%%+6.4u]:%+6.4u|[%%6.0u]:%6.0u|%4.0u|\n", 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0));
	// printf("ft_printf return %d\n", ft_printf("[%%u]:%u|[%%4u]:%4u|[%%+4u]:%+4u|[%%+- 4u]:%+- 4u|[%% 05u]:% 05u|[%%- 04.0u]:%- 04.0u|[%% 04.3u]:% 04.3u|[%%-+2.4u]:%-+2.4u|[%%+6.4u]:%+6.4u|[%%6.0u]:%6.0u|%4.0u|\n", 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0));
	// printf("printf return %d\n", printf("[%%u]:%u|[%%4u]:%4u|[%%+4u]:%+4u|[%%+- 4u]:%+- 4u|[%% 05u]:% 05u|[%%- 04.0u]:%- 04.0u|[%% 04.3u]:% 04.3u|[%%-+2.4u]:%-+2.4u|[%%+6.4u]:%+6.4u|[%%6.0u]:%6.0u||\n", 10, 10, 10, 10, 10, 10, 10, 10, 10, 10));
	// printf("ft_printf return %d\n", ft_printf("[%%u]:%u|[%%4u]:%4u|[%%+4u]:%+4u|[%%+- 4u]:%+- 4u|[%% 05u]:% 05u|[%%- 04.0u]:%- 04.0u|[%% 04.3u]:% 04.3u|[%%-+2.4u]:%-+2.4u|[%%+6.4u]:%+6.4u|[%%6.0u]:%6.0u||\n", 10, 10, 10, 10, 10, 10, 10, 10, 10, 10));

	// printf("printf return %d\n", printf("[%%x]:%x|[%%4x]:%4x|[%%+4x]:%+4x|[%%+- 4x]:%+- 4x|[%% 05x]:% 05x|[%%- 04.0x]:%- 04.0x|[%% 04.3x]:% 04.3x|[%%-+2.4x]:%-+2.4x|[%%+6.4x]:%+6.4x|[%%6.0x]:%6.0x|%4.0x|\n", 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0));
	// printf("ft_printf return %d\n", ft_printf("[%%x]:%x|[%%4x]:%4x|[%%+4x]:%+4x|[%%+- 4x]:%+- 4x|[%% 05x]:% 05x|[%%- 04.0x]:%- 04.0x|[%% 04.3x]:% 04.3x|[%%-+2.4x]:%-+2.4x|[%%+6.4x]:%+6.4x|[%%6.0x]:%6.0x|%4.0x|\n", 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0));
	// printf("printf return %d\n", printf("[%%x]:%x|[%%4x]:%4x|[%%+4x]:%+4x|[%%+- 4x]:%+- 4x|[%% 05x]:% 05x|[%%- 04.0x]:%- 04.0x|[%% 04.3x]:% 04.3x|[%%-+2.4x]:%-+2.4x|[%%+6.4x]:%+6.4x|[%%6.0x]:%6.0x|%4.0x|\n", 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 0));
	// printf("ft_printf return %d\n", ft_printf("[%%x]:%x|[%%4x]:%4x|[%%+4x]:%+4x|[%%+- 4x]:%+- 4x|[%% 05x]:% 05x|[%%- 04.0x]:%- 04.0x|[%% 04.3x]:% 04.3x|[%%-+2.4x]:%-+2.4x|[%%+6.4x]:%+6.4x|[%%6.0x]:%6.0x|%4.0x|\n", 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 0));

	// printf("printf return %d\n", printf("[%%X]:%X|[%%4X]:%4X|[%%+4X]:%+4X|[%%+- 4X]:%+- 4X|[%% 05X]:% 05X|[%%- 04.0X]:%- 04.0X|[%% 04.3X]:% 04.3X|[%%-+2.4X]:%-+2.4X|[%%+6.4X]:%+6.4X|[%%6.0X]:%6.0X|%4.0X|\n", 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0));
	// printf("ft_printf return %d\n", ft_printf("[%%X]:%X|[%%4X]:%4X|[%%+4X]:%+4X|[%%+- 4X]:%+- 4X|[%% 05X]:% 05X|[%%- 04.0X]:%- 04.0X|[%% 04.3X]:% 04.3X|[%%-+2.4X]:%-+2.4X|[%%+6.4X]:%+6.4X|[%%6.0X]:%6.0X|%4.0X|\n", 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0));

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