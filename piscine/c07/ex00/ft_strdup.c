/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:46:05 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/22 14:06:12 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *str)
{
	int		i;
	int		size;
	char	*arr;

	size = 0;
	while (str[size] != '\0')
		size++;
	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (!arr)
		return (0);
	i = 0;
	while (i < size + 1)
	{
		arr[i] = str[i];
		i++;
	}
	return (arr);
}
