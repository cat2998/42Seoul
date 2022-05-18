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
	while (size > 0)
	{
		if (temp[size] == (char)c)
			return (&temp[size]);
		size--;
	}
	if (temp[size] == (char)c)
		return (&temp[size]);
	return (0);
}
