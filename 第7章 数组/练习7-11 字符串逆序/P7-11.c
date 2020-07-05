#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    int k = 0;
    char line[80];
    while ((line[k] = getchar()) != '\n')
        k++;
    for (k=k-1;k>=0;k--)
    {
        putchar(line[k]);
    }
    return 0;
}