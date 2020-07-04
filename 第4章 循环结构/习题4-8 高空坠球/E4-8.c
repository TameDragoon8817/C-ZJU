#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main (void)
{
    int height, n, i;
    double length=0.0, level,item=0.0;
    scanf ("%d%d", &height, &n);
    if (n>0){
    item = height * 1.0;
    length = length + item;
    for (i = 1; i <= n;i++){
        if (i==1) {
        }
        else {
            length = length + item * 2.0;
        }
        item = item / 2;
    }
    level = item;
    printf("%.1f %.1f", length, level);}
    else {
        printf("0.0 0.0");
    }
    return 0;
}