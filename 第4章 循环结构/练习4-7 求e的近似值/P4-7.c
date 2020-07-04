#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
double factorial(int n);
int main (void)
{
    int n;
    double result;
    scanf("%d", &n);
    result = 1 + factorial(n);
    printf("%.8f", result);
    return 0;
}
double factorial(int n)
{
    int i;
    double item, result = 0, denominator=1;
    for (i = 1; i <= n;i++){        
        denominator = denominator * i;
        item = 1 / denominator;
        result = result + item;
    }
    return result;
}