#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main (void)
{
    int i,a,n,sum=0,t=0;
    scanf("%d %d", &a, &n);
    for(i=1;i<=n;i++)
    {
        t=t*10+a;
        sum=sum+t;
    }
    printf("s = %d\n", sum);
    return 0;
}