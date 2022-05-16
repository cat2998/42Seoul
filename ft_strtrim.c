/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:34:52 by jgwon             #+#    #+#             */
/*   Updated: 2022/05/15 20:15:39 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_setbegin(char const *s1, char const *set);
size_t	ft_setend(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	size_t	begin;
	size_t	end;
	char	*str;

	begin = ft_setbegin(s1, set);
	end = ft_setend(s1, set);
	str = (char *)malloc(sizeof(char) * (end - begin + 1));
	if (!str)
		return (0);
	i = 0;
	while (begin < end)
		str[i++] = s1[begin++];
	str[i] = '\0';
	return (str);
}

size_t	ft_setbegin(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break;
		i++;
	}
	return (i);
}

size_t	ft_setend(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[len - 1 - i]) == 0)
			break;
		i++;
	}
	return (len - i);
}
