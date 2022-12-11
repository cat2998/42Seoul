/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:20:22 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/26 17:20:28 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_size(char *str, char *charset);
char	**ft_split_s(char **split, char *str, char *charset, int size);
int		ft_compare(char *str, char *charset, int str_i);
char	*ft_strncpy(char *str, int str_i, char *s, int n);

char	**ft_split(char *str, char *charset)
{
	char	**split;

	split = (char **)malloc(sizeof(char *) * (ft_size(str, charset) + 1));
	if (!split)
		return (0);
	return (ft_split_s(split, str, charset, (ft_size(str, charset) + 1)));
}

int	ft_size(char *str, char *charset)
{
	int	i;
	int	flag;
	int	count;

	i = 0;
	flag = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (!ft_compare(str, charset, i)
			&& (ft_compare(str, charset, i + 1) || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split_s(char **split, char *str, char *charset, int size)
{
	int		i;
	int		split_i;
	int		flag;
	char	*s;

	i = 0;
	flag = -1;
	split_i = 0;
	while (split_i < size - 1)
	{
		if (flag == -1 && ft_compare(str, charset, i) == 0)
			flag = i;
		else if (flag != -1 && (ft_compare(str, charset, i) || str[i] == '\0'))
		{
			s = (char *)malloc(sizeof(char) * (i - flag) + 1);
			if (!s)
				return (0);
			split[split_i++] = ft_strncpy(str, flag, s, i - flag);
			flag = -1;
		}
		i++;
	}
	split[split_i] = 0;
	return (split);
}

int	ft_compare(char *str, char *charset, int str_i)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (str[str_i] == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strncpy(char *str, int str_i, char *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s[i] = str[str_i + i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
