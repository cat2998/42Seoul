
#include "get_next_line_bonus.h"

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
    if (!s)
		return (-1);
	temp = (char *)s;
	while (temp[i] != '\0')
	{
		if (temp[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}