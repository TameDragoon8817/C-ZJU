#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main (void)
{
	double item,sum,N,flag,denominator,a;
	scanf ("%lf",&N);
	flag=1;
	denominator=1;
	for (a=1;a<=N;a++){
		item=flag*a/denominator;
		sum=sum+item;
		denominator=denominator+2;
		flag=flag*(-1);
	}
	printf ("%.3f",sum);
	return 0;
}