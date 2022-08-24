#include <stdio.h>
#include <unistd.h>

int main(void)
{
    write(1, "3", 1);
    write(1, "2", 1);
    if (0)
    {
        write(1, "4", 1);
    }
    return 0;
}