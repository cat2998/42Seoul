#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t  i;
    unsigned char   *temp1;
    unsigned char   *temp2;

    i = 0;
    temp1 = (unsigned char *)s1;
    temp2 = (unsigned char *)s2;
    while (i < n)
    {
        if (temp1[i] != temp2[i])
            return ((int)(temp1[i] - temp2[i]));
        i++;
    }
    return (0);
}