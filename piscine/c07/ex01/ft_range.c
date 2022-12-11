/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:53:49 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/24 18:16:38 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*arr;

	if (min >= max)
		return (0);
	arr = (int *)malloc(sizeof(int) * (max - min));
	if (!arr)
		return (0);
	i = 0;
	while (min < max)
		arr[i++] = min++;
	return (arr);
}
