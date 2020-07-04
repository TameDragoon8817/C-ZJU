#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
double fact(double n);
int main(void)
{
    double S,eps;
    scanf("%lf", &eps);
    S = fact(eps);
    printf("sum = %lf", S);
    return 0;
}
double fact(double n)
{
    int c=1,flag=1;
    double result = 0;
    while (1.0/c>n)
    {
        result = result + flag * 1.0 / c;
        flag = -flag;
        c=c+3;
    }
    result = flag * 1.0 / c + result;
    return result;
}