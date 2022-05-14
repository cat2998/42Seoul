#include "libft.h"

/*
역할 : dest 의 처음부터 n 바이트까지 0으로 세팅
*/
void    ft_bzero(void *dest, size_t n)
{
    size_t          i;
    unsigned char   *temp;

    i = 0;
    temp = dest;
    while (i < n)
    {
        temp[i] = 0;
        i++;
    }
    return ;
}