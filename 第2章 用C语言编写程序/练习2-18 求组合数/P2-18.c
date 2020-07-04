#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
double factorial(int n);
int main (void)
{
    double result;
    int m,n;
    scanf("%d%d",&m,&n);
    result=factorial(n)/(factorial(n-m)*factorial(m));
    printf("result = %.0f",result);
   
    return 0;
}
double factorial(int n)
{
    int i;
    double fact=1;
    for(i=1;i<=n;i++)
        fact=fact*i;
    return fact;
}