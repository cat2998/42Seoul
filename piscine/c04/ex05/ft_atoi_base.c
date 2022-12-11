/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:03:22 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/17 13:14:57 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_space(char *str, int *str_i);
int		ft_minus(char *str, int *str_i);
int		ft_base_check(char *base);
int		ft_is_base(char *str, char *base, int str_i);

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	minus;
	int	basenum;
	int	result;

	i = 0;
	result = 0;
	ft_space(str, &i);
	minus = ft_minus(str, &i);
	basenum = ft_base_check(base);
	if (basenum == 0)
		return (0);
	while (ft_is_base(str, base, i) != -1)
	{
		result *= basenum;
		result += ft_is_base(str, base, i);
		i++;
	}
	result *= minus;
	return (result);
}

void	ft_space(char *str, int *str_i)
{
	int	i;

	i = 0;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == ' ' \
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
	{
		i++;
	}
	*str_i = i;
}

int	ft_minus(char *str, int *str_i)
{
	int	i;
	int	minus;

	i = *str_i;
	minus = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	*str_i = i;
	return (minus);
}

int	ft_base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == '\f' \
				|| base[i] == '\t' || base[i] == ' ' || base[i] == '\n' \
				|| base[i] == '\r' || base[i] == '\v')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	ft_is_base(char *str, char *base, int str_i)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (str[str_i] == base[i])
			return (i);
		i++;
	}
	return (-1);
}
