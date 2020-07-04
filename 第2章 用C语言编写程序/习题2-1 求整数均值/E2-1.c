#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main (void)
{
    int a,b,c,d,sum;
    double average;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    sum=a+b+c+d;
    average=(a+b+c+d)/4.0;
    printf ("Sum = %d; Average = %.1f",sum,average);
    return 0;
}