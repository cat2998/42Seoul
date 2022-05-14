#include "libft.h"

/*
역할 : src가 가리키는 곳부터 n 바이트를 dest가 가리키는 곳에 복사한다.
서로 메모리 영역이 겹쳐져 있으면 X
*/
void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t          i;
    unsigned char   *dest_temp;
    unsigned char   *src_temp;

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