#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main (void)
{
    int n, item, i, min, number = 1;
    scanf("%d", &n);
    for (i = 1; i <= n;i++,number++)
    {
        scanf("%d", &item);
        if (number==1){
            min = item;
        }
        else {
            if (item<min){
                min = item;
            }
        }
    }
    printf("min = %d", min);
    return 0;
}