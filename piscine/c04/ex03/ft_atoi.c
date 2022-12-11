/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:22:37 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/16 21:45:31 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_space(char *str, int *str_i);
int		ft_minus(char *str, int *str_i);

int	ft_atoi(char *str)
{
	int	i;
	int	minus;
	int	result;

	i = 0;
	result = 0;
	ft_space(str, &i);
	minus = ft_minus(str, &i);
	while ('0' <= str[i] && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
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
