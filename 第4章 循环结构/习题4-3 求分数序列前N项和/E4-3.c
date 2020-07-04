#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main (void)
{
    int N, i;
    double item, result=0.0,a,b,c;
    a = 2.0;
    b = 1.0;
    scanf("%d", &N);
    if (N>0){
        for (i = 1; i <= N; i++)
        {
            item = (a / b)*1.0;
            result =(result + item)*1.0;
            c = a;
            a = c + b;
            b = c;
        }
    }
            printf("%.2f", result);
    return 0;
}
