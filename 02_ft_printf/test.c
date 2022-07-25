#include <stdio.h>

int main(void)
{
    char c = 'a';
    char *p;

    p = &c;

    printf("%+c\n", 'a');
    printf("%+s\n", "abc");
    printf("%+p\n", c);
    printf("%+d\n", 43243);
    printf("%+c\n", 'a');
}