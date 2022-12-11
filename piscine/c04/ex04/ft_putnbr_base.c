/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:32:13 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/17 21:49:10 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_base_check(char *base);
void	ft_print(char *arr, int i);
void	ft_putnbr_base2(unsigned int nbr, char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	int				basenum;
	char			arr[35];
	unsigned int	i;

	if (nbr < 0)
	{
		if (ft_base_check(base) == 0)
			return ;
		i = nbr * -1;
		ft_putnbr_base2(i, base);
	}
	else
	{
		i = 34;
		basenum = ft_base_check(base);
		if (basenum == 0)
			return ;
		while (nbr / basenum != 0)
		{
			arr[i--] = base[nbr % basenum];
			nbr /= basenum;
		}
		arr[i] = base[nbr];
		ft_print(arr, i);
	}
}

int	ft_base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
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

void	ft_print(char *arr, int i)
{
	while (i < 35)
	{
		write(1, &arr[i++], 1);
	}
}

void	ft_putnbr_base2(unsigned int nbr, char *base)
{
	int				basenum;
	char			arr[35];
	unsigned int	i;

	i = 34;
	basenum = ft_base_check(base);
	if (basenum == 0)
		return ;
	while (nbr / basenum != 0)
	{
		arr[i--] = base[nbr % basenum];
		nbr /= basenum;
	}
	arr[i] = base[nbr];
	write(1, "-", 1);
	ft_print(arr, i);
}
