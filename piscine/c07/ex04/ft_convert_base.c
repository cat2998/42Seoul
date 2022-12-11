/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:29:49 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/25 13:13:21 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_check_base(char *base);
int		ft_atoi_base(char *nbr, char *base);
int		ft_space_minus(char *str, int *str_i);
int		ft_base_size(char *base);
int		ft_is_base(char *str, char *base, int str_i);
char	*ft_putnbr_base(int nbr, char *base);
int		ft_putnbr_bminus(unsigned int nbr, char *base, char *str, int base_len);
char	*ft_malloc_str(char *arr, int i);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (ft_check_base(base_from) || ft_check_base(base_to))
		return (0);
	return (ft_putnbr_base(ft_atoi_base(nbr, base_from), base_to));
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	minus;
	int	base_len;
	int	result;

	i = 0;
	result = 0;
	minus = ft_space_minus(str, &i);
	base_len = ft_base_size(base);
	while (ft_is_base(str, base, i) != -1)
	{
		result *= base_len;
		result += ft_is_base(str, base, i);
		i++;
	}
	result *= minus;
	return (result);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		base_len;
	char	arr[35];
	char	*str;

	base_len = ft_base_size(base);
	if (nbr < 0)
		i = ft_putnbr_bminus(nbr * (-1), base, arr, base_len);
	else
	{
		i = 0;
		while (nbr / base_len != 0)
		{
			arr[i] = base[nbr % base_len];
			nbr /= base_len;
			i++;
		}
		arr[i++] = base[nbr];
	}
	str = ft_malloc_str(arr, i);
	return (str);
}

int	ft_putnbr_bminus(unsigned int nbr, char *base, char *arr, int base_len)
{
	int	i;

	i = 0;
	while (nbr / base_len != 0)
	{
		arr[i] = base[nbr % base_len];
		nbr /= base_len;
		i++;
	}
	arr[i++] = base[nbr];
	arr[i++] = '-';
	return (i);
}

char	*ft_malloc_str(char *arr, int i)
{
	int		j;
	char	*str;

	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (0);
	i--;
	j = 0;
	while (i != 0)
	{
		str[j] = arr[i];
		i--;
		j++;
	}
	str[j++] = arr[i];
	str[j] = '\0';
	return (str);
}
