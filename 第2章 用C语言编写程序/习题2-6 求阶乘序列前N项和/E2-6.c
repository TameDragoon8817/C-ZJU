#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main (void)
{
    int N, item = 1, result = 0, i;
    scanf("%d", &N);
    if (N>0&&N<=12){
        for (i = 1; i <= N;i++){
            item = item * i;
            result = result + item;
        }
    }
    printf("%d", result);
    return 0;
}