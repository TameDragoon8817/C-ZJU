#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main (void)
{
	int N,i;
	double S=0,item;
	scanf ("%d",&N);
	for (i=1;i<=N;i++){
		item=1.0/i;
		S=S+item;
	}
	printf ("sum = %.6f",S);
	return 0;
}