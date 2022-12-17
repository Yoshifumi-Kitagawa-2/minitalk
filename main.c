#include <stdio.h>
#include "minitalk.h"

int main(void)
{
    int a = 0b00000001;
    printf("%d", a);
    return(0);
}

uint8_t ft_change(int binary)
{
    uint8_t n;
    uint8_t base;

    n = 0;
    base = 1;
    while (binary > 0)
    {
        n += (n % 10)*base;
        binary /= 10;
        base = base*2;
    }
    return (n);
}