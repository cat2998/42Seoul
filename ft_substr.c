#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t  i;
    char    *str;

    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str || !s)
        return (0);
    i = 0;
    while (i < len && start + i < ft_strlen(s))
    {
        str[i] = s[start + i];
        i++;
    }
    str[i] = '\0';
    return (str);
}