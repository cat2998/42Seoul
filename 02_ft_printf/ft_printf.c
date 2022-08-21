/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:08:38 by jgwon             #+#    #+#             */
/*   Updated: 2022/08/21 19:25:03 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

typedef struct s_info
{
	int	minus;
	int	plus;
	int	space;
	int	zero;
	int	sharp;
	int	width;
	int precision;
	int pn;
	char	type;
}	t_info;

const char *ft_info(const char *format, va_list ap)
{
	while (*format != 'd')
	{
		// ft_checkflag(format);
		printf("%c", *format);
		format++;
	}
	return format;
}

int	ft_myprintf(va_list ap, const char *format)
{
	// int	a;
	// char	*p;

	while (*format != 0)
	{
		if (*format == '%')
		{
			format++;
			format = ft_info(format, ap);
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
	ft_myprintf(ap, format);
	va_end(ap);

	return 0;
}

int main(void)
{
	ft_printf("Hello%dWorld%d!!!%d", 10, 20, 30);
}