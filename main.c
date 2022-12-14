#include <stdio.h> 

int main(void)
{
    char ch;
    int i;

    ch = 'a';
    i = ch & 0b00000001;
    printf("%d", i);
    return (0);
}