#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main (void)
{
    int n,item,i;
    scanf("%d", &n);
    for (i=0;i<=n;i++){
        item=pow(3,i);
        printf ("pow(3,%d) = %d\n",i,item);
    }
    return 0;
}