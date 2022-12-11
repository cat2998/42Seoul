/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:02:30 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/16 20:06:20 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_len(char *dest);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = 0;
	dest_len = ft_len(dest);
	src_len = ft_len(src);
	if (size <= dest_len)
		return (src_len + size);
	while (dest_len + i + 1 < size && src [i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

unsigned int	ft_len(char *dest)
{
	unsigned int	i;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	return (i);
}
