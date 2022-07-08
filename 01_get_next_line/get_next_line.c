/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:28:21 by jgwon             #+#    #+#             */
/*   Updated: 2022/07/07 02:35:34 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_to_newline(int fd, char *sum)
{
	char	*buf;
	int		read_size;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buf)
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

	result = (char *)malloc(sizeof(char) * (n + 2));
	if(!result)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (0);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	static char	*sum;

	sum = ft_read_to_newline(fd, sum);
	if (!sum || sum[0] == '\0')
		return (0);
	i = ft_find_newline(sum);
	line = ft_get_line(sum, i);
	sum = ft_substr(sum, i + 1, ft_strlen(sum) - i);
	if (!line && !sum)
		return (0);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>
int main(void)
{
	int	fd;
	char *answer;
	if (0 < (fd = open("./test.txt", O_RDONLY)))
	{
		while ((answer = get_next_line(fd)) != 0)
		{
			printf("return : %s", answer);
		}
		close(fd);
	}
	else
	{
		printf("파일 읽기 실패");
	}
	return 0;
}