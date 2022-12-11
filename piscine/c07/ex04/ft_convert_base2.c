/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:58:26 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/23 16:10:12 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_base(char *base);
int	ft_base_size(char *base);
int	ft_space_minus(char *str, int *str_i);
int	ft_is_base(char *str, char *base, int str_i);

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\t' || base[i] == '\n' || base[i] == '\v'
			|| base[i] == '\f' || base[i] == '\r')
			return (1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (1);
	return (0);
}

int	ft_base_size(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int	ft_space_minus(char *str, int *str_i)
{
	int	i;
	int	minus;

	i = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	*str_i = i;
	return (minus);
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
