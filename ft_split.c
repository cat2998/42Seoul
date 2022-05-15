/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:33:20 by jgwon             #+#    #+#             */
/*   Updated: 2022/05/15 20:15:06 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_size(char const *str, char c);
int		ft_compare(char const *str, char c, int i);
char	**ft_split_s(char **split, char const *s, char c, int size);
char	*ft_strncpy(char const *s, int begin, int len, char *str);

char	**ft_split(char const *s, char c)
{
	int		size;
	char	**split;

	size = ft_size(s, c) + 1;
	split = (char **)malloc(sizeof(char *) * size);
	if (!split)
		return (0);
	return (ft_split_s(split, s, c, size));
}

int	ft_size(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (!ft_compare(str, c, i)
			&& (ft_compare(str, c, i + 1) || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

int	ft_compare(char const *str, char c, int i)
{
	if (str[i] == c)
		return (1);
	return (0);
}

char	**ft_split_s(char **split, char const *s, char c, int size)
{
	int		i;
	int		begin;
	int		split_i;
	char	*str;

	i = 0;
	begin = -1;
	split_i = 0;
	while (split_i < size - 1)
	{
		if (begin == -1 && ft_compare(s, c, i) == 0)
			begin = i;
		else if (begin != -1 && (ft_compare(s, c, i) || s[i] == '\0'))
		{
			str = (char *)malloc(sizeof(char) * (i - begin) + 1);
			if (!str)
				return (0);
			split[split_i++] = ft_strncpy(s, begin, i - begin, str);
			begin = -1;
		}
		i++;
	}
	split[split_i] = 0;
	return (split);
}

char	*ft_strncpy(char const *s, int begin, int len, char *str)
{
	int	i;

	i = 0;
	while (i < len)
	{
		str[i] = s[begin + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
