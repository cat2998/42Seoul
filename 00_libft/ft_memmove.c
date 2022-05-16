/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:31:12 by jgwon             #+#    #+#             */
/*   Updated: 2022/05/15 16:58:22 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_temp;
	unsigned char	*src_temp;

	i = 0;
	dest_temp = dest;
	src_temp = (unsigned char *)src;
	if (dest < src)
	{
		while (i < n)
		{
			dest_temp[i] = src_temp[i];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			dest_temp[n - 1 - i] = src_temp[n - 1 - i];
			i++;
		}
	}
	return (dest);
}
