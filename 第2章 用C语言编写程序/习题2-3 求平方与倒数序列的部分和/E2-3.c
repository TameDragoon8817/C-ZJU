#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main (void)
{
    int m, n, i;
    double S = 0, item;
    scanf("%d%d", &m, &n);
    for (i = m; i <= n;i++){
        item = 1.0*pow(i, 2) + 1.0 / i;
        S = S + item;
    }
    printf("sum = %.6f", S);
    return 0;
}