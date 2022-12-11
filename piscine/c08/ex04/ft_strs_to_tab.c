/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:28:02 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/25 14:56:46 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int		ft_size(char *str);
char	*ft_strdup(char *src);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*str;

	str = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < ac)
	{
		str[i].size = ft_size(av[i]);
		str[i].str = av[i];
		str[i].copy = ft_strdup(av[i]);
		i++;
	}
	str[i].size = 0;
	str[i].str = 0;
	str[i].copy = 0;
	return (str);
}

int	ft_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*copy;

	size = ft_size(src);
	copy = (char *)malloc(sizeof(char) * (size + 1));
	if (!copy)
		return (0);
	i = 0;
	while (i < size + 1)
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
}
