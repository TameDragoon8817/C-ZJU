#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main (void)
{
    int N,item,remain=1,i;
    scanf("%d", &N);
    for (i = 1; i < N;i++){
        item = (1 + remain) * 2;
        remain = item;
    }
    printf("%d", item);
    return 0;
}