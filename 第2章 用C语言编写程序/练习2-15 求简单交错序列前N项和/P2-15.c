#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main (void)
{
	int N,i,flag,a;
	double item,S=0;
	scanf ("%d",&N);
	flag=1;
	for (i=1;i<=N;i++){
		a=3*i-2;
		item=1.0*flag/a;
		S=S+item;
		flag=-flag;
	}
	printf ("sum = %.3f",S);
	return 0;
}