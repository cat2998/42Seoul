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

int		ft_compare(char const *str, char c, int i);
char	**ft_split_s(char **split, char const *s, char c, int size);
char	*ft_strncpy(char const *s, int begin, int len, char *str);
void	ft_split_free(char **split, int split_i);

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	char	**split;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (!ft_compare(s, c, i)
			&& (ft_compare(s, c, i + 1) || s[i + 1] == '\0'))
			count++;
		i++;
	}
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (0);
	return (ft_split_s(split, s, c, count + 1));
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
			{
				ft_split_free(split, split_i);
				return (0);
			}
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

void	ft_split_free(char **split, int split_i)
{
	int	i;

	i = 0;
	while (i < split_i)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return ;
}
