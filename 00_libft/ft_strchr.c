/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:38:05 by jgwon             #+#    #+#             */
/*   Updated: 2022/05/15 17:47:09 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)s;
	while (temp[i] != '\0')
	{
		if (temp[i] == (char)c)
			return (&temp[i]);
		i++;
	}
	if (temp[i] == (char)c)
		return (&temp[i]);
	return (0);
}
