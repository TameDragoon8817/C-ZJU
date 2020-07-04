#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main (void)
{
	float use,cost;
	scanf ("%f",&use);
	if (use<=50&&use>0){
		cost=0.53*use;
		printf ("cost = %.2f",cost);
	}
	else if (use>50){
		cost=0.53*50+0.58*(use-50);
		printf ("cost = %.2f",cost);
	}
	else {
		printf ("Invalid Value!");
	}
	return 0;
}