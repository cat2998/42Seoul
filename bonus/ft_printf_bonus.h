/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 03:05:20 by jgwon             #+#    #+#             */
/*   Updated: 2022/08/29 21:12:01 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_info
{
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		sharp;
	int		width;
	int		prec;
	int		prec_n;
	int		sign;
	int		base;
	char	type;
}	t_info;

void			init_info(t_info *info);
void			ft_info_check(const char *format, t_info *info);
const char		*ft_info(const char *format, t_info *info);
int				ft_print_none(t_info *info);
int				ft_print_czerospace(t_info *info);
int				ft_print_cpercent(char c, t_info *info);
int				ft_putstrprec(char *str, t_info *info);
int				ft_print_szerospace(char *str, t_info *info);
int				ft_print_s(char *str, t_info *info);
void			base_check(t_info *info);
int				ft_len(unsigned long long n, t_info *info);
int				ft_putnbr(unsigned long long n, t_info *info);
unsigned int	sign_check(int d, t_info *info);
int				width_check(int count, t_info *info);
int				ft_print_plusspace(t_info *info);
int				ft_print_prec(unsigned long long n, t_info *info);
int				ft_print_width(int cnt, unsigned long long n, t_info *info);
int				ft_print_zero(int cnt, unsigned long long n, t_info *info);
int				ft_print_di(int d, t_info *info);
int				ft_print_sharp(unsigned long long d, t_info *info);
int				ft_print_uxp(unsigned long long d, t_info *info);
int				ft_format_info_print(va_list ap, t_info *info);
int				ft_format_printf(va_list ap, const char *format);
int				ft_printf(const char *format, ...);

#endif