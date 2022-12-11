/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:40:34 by jgwon             #+#    #+#             */
/*   Updated: 2022/01/23 14:48:51 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
void	ft_arr_input(int size, char *arr, char **strs, char *sep);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		total_size;
	char	*arr;

	i = 0;
	total_size = 0;
	while (i < size)
		total_size += ft_strlen(strs[i++]);
	if (size <= 0)
		total_size = 1;
	else
		total_size += (size - 1) * ft_strlen(sep) + 1;
	arr = (char *)malloc(sizeof(char) * total_size);
	if (!arr)
		return (0);
	ft_arr_input(size, arr, strs, sep);
	return (arr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_arr_input(int size, char *arr, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (*strs[i])
			arr[j++] = *(strs[i]++);
		if (i != size - 1)
		{
			k = 0;
			while (*(sep + k))
				arr[j++] = *(sep + k++);
		}
		i++;
	}
	arr[j] = '\0';
	return ;
}
