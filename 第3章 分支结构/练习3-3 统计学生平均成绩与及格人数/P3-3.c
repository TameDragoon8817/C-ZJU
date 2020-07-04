#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main (void)
{
    int N,i,score,sum=0,count=0;
    double average;
    scanf("%d",&N);
	count = 0;
	for(i=1;i<=N;i++)
    {
        scanf("%d",&score);
        if(score>60||score==60)
        {
            count++;
        }
        sum=sum+score;
    }
    average=1.0*sum/N;
    if (N>0){
    printf("average = %0.1f\n",average);
    printf("count = %d",count);}
    else
        printf("average = 0.0\ncount = 0");
    return 0;
}