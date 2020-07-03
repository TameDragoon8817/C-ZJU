#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main (void)
{
	double x,y;
	scanf ("%lf",&x);
	if (x>=0){
		y=pow(x,0.5);
	}
	else{
		y=pow(x+1,2)+2*x+1/x;
	}
	printf ("f(%.2f) = %.2f",x,y);
	return 0;
}