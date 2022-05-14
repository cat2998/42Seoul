#include "libft.h"

/*
역할 : dest가 가리키는 메모리 영역의 첫번째부터 n 바이트를 c로 채운다.
c는 함수내부적으로 unsigned char로 형변환되어서 사용
*/
void    *ft_memset(void *dest, int c, size_t n)
{
    size_t          i;
    unsigned char   *temp;

    i = 0;
    temp = dest;
    while (i < n)
    {
        temp[i] = (unsigned char)c;
        i++;
    }
    return (dest);
}