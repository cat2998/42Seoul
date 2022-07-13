/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:40:33 by jgwon             #+#    #+#             */
/*   Updated: 2022/07/13 19:33:51 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_to_newline(int fd, char *sum)
{
	char	*buf;
	int		read_size;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	read_size = 1;
	while (ft_strchr(sum, '\n') < 0 && read_size != 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(buf);
			return (0);
		}
		buf[read_size] = '\0';
		sum = ft_strjoin(sum, buf);
	}
	free(buf);
	return (sum);
}

int	ft_find_newline(char *sum)
{
	int	i;

	i = 0;
	while (sum[i] != '\0' && sum[i] != '\n')
		i++;
	return (i);
}

char	*ft_get_line(char *sum, int n)
{
	int		i;
	char	*result;

	if (sum[0] == '\0')
		return (0);
	result = (char *)malloc(sizeof(char) * (n + 2));
	if (!result)
		return (0);
	i = 0;
	while (sum[i] != '\0' && i < n + 1)
	{
		result[i] = sum[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_substr(char *sum, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (len == 0)
	{
		free(sum);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (0);
	i = 0;
	while (sum[start + i] != '\0' && i < len)
	{
		str[i] = sum[start + i];
		i++;
	}
	str[i] = '\0';
	free(sum);
	return (str);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	static char	*sum[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX)
		return (0);
	sum[fd] = ft_read_to_newline(fd, sum[fd]);
	if (!sum[fd])
		return (0);
	i = ft_find_newline(sum[fd]);
	line = ft_get_line(sum[fd], i);
	sum[fd] = ft_substr(sum[fd], i + 1, ft_strlen(sum[fd]) - i);
	return (line);
}
