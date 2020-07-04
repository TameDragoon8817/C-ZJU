#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    int N,i,grade,a=0,b=0,c=0,d=0,e=0;
    scanf("%d", &N);
    for (i = 1; i <= N;i++){
        scanf("%d", &grade);
        if (grade>=90){
            a++;
        }
        else if (grade>=80){
            b++;
        }
        else if (grade>=70){
            c++;
        }
        else if (grade>=60){
            d++;
        }
        else {
            e++;
        }
    }
    printf("%d %d %d %d %d", a, b, c, d, e);
    return 0;
}