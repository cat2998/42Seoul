/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:40:33 by jgwon             #+#    #+#             */
/*   Updated: 2022/07/08 21:44:13 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_substr(char *s, unsigned int start, size_t len)
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
	free(s);
	return (str);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	static char	*sum[OPEN_MAX];

	sum[fd] = ft_read_to_newline(fd, sum[fd]);
	if (!sum[fd] || sum[fd][0] == '\0')
	{
		free(sum[fd]);
		return (0);
	}
	i = ft_find_newline(sum[fd]);
	line = ft_get_line(sum[fd], i);
	sum[fd] = ft_substr(sum[fd], i + 1, ft_strlen(sum[fd]) - i);
	if (!line && !sum[fd])
		return (0);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int main(void)
// {
// 	int	fd1, fd2, fd3;
// 	char *answer1 = 0, *answer2 = 0, *answer3;

// 	fd1 = open("./test.txt", O_RDONLY);
// 	fd2 = open("./test2.txt", O_RDONLY);
// 	fd3 = open("./test3.txt", O_RDONLY);
// 	if (0 < fd1 && 0 < fd2 && 0 < fd3)
// 	{
// 		while (answer1 != 0 || answer2 != 0 || answer3 != 0)
// 		{
// 			if ((answer1 = get_next_line(fd1)) != 0)
// 			{
// 				printf("fd1 : %s", answer1);
// 			}
// 			if ((answer2 = get_next_line(fd2)) != 0)
// 			{
// 				printf("fd2 : %s", answer2);
// 			}
// 			if ((answer3 = get_next_line(fd3)) != 0)
// 			{
// 				printf("fd3 : %s", answer3);
// 			}
// 		}
// 	}
// 	else
// 	{
// 		printf("파일 읽기 실패");
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return 0;
// }