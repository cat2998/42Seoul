/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:35:59 by jgwon             #+#    #+#             */
/*   Updated: 2022/07/13 19:33:30 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_temp;
	unsigned char	*src_temp;

	if (!dest && !src)
		return (0);
	i = 0;
	dest_temp = dest;
	src_temp = (unsigned char *)src;
	while (i < n)
	{
		dest_temp[i] = src_temp[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		total_size;
	char	*arr;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1)
			return (0);
		s1[0] = '\0';
	}
	total_size = ft_strlen(s1) + ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (total_size + 1));
	if (!arr)
		return (0);
	ft_memcpy(arr, s1, ft_strlen(s1));
	ft_memcpy(arr + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	return (arr);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}
