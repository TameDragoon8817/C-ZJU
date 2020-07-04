#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main (void)
{
    int N, i;
    double S,item;
    scanf("%d", &N);
    for (i = 1; i <= N;i++){
        item = sqrt(i);
        S = S + item;
    }
    printf("sum = %.2f", S);
    return 0;
}