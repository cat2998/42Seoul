#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    size_t  i;
    unsigned char   *temp;

    i = 0;
    temp = (unsigned char *)s;
    while (i < n)
    {
        if (temp[i] == (unsigned char)c)
            return (&temp[i]);
        i++;
    }
    return (0);
}