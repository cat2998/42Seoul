/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:50:40 by jgwon             #+#    #+#             */
/*   Updated: 2022/05/15 18:15:16 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	str = (char *)haystack;
	if (needle[i] == '\0')
		return (&str[i]);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] == needle[j] && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
