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
	while (needle[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[i])
		{
			j = 0;
			while (haystack[i + j] == needle[j])
			{
				j++;
				if (needle[j] == '\0')
					return (&str[i]);
			}
		}
		i++;
	}
	return (0);
}
