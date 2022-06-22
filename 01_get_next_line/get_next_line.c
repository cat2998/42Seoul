/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:28:21 by jgwon             #+#    #+#             */
/*   Updated: 2022/06/08 21:33:23 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*copy;

	size = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * (size + 1));
	if (!copy)
		return (0);
	i = 0;
	while (i < size + 1)
	{
		copy[i] = s1[i];
		i++;
	}
	return (copy);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_temp;
	unsigned char	*src_temp;

	if (!dest && !src)
		return (0);
	i = 0;
	dest_temp = dest;
	src_temp = (unsigned char *)src;
	while (i < n)
	{
		dest_temp[i] = src_temp[i];
		i++;
	}
	return (dest);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_size;
	char	*arr;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	total_size = ft_strlen(s1) + ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (total_size + 1));
	if (!arr)
		return (0);
	ft_memcpy(arr, s1, ft_strlen(s1));
	ft_memcpy(arr + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (arr);
}

int	ft_strchr(const char *s, int c)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)s;
	while (temp[i] != '\0')
	{
		if (temp[i] == (char)c)
			return (i);
		i++;
	}
	if (temp[i] == (char)c)
		return (i);
	return (-1);
}

char	*get_next_line(int fd)
{
	char	*buf;
	int		i;
	char	*sum = NULL;
	char	*result = NULL;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buf)
		return (0);

	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		sum = ft_strjoin(sum, buf);
		printf("sum : %s||\n", sum);
		if ((i = ft_strchr(sum, '\n')) >= 0)
		{
			printf("find \\n!!\n");
			result = (char *)malloc(sizeof(char) * (i + 1));
			if(!result)
				return (0);
			int j = 0;
			while (i >= 0)
			{
				result[j] = sum[j];
				j++;
				i--;
			}
			printf("result : %s\n", result);
			break ;
		}
	}
	free(buf);
	return result;
}

#include <fcntl.h>
int main(void)
{
	int	fd;
	if (0 < (fd = open("./test.txt", O_RDONLY)))
	{
		get_next_line(fd);
		close(fd);
	}
	else
	{
		printf("파일 읽기 실패");
	}
	return 0;
}