/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:40:00 by jgwon             #+#    #+#             */
/*   Updated: 2022/05/15 17:54:11 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	size_t	size;

	temp = (char *)s;
	size = ft_strlen(s);
	if (size != 0)
	{
		while (size > 0)
		{
			if (temp[size - 1] == (char)c)
				return (&temp[size - 1]);
			size--;
		}
	}
	return (0);
}
