#include<stdio.h>
#include<math.h>
int main (void)
{
	double x,result;
	scanf("%lf",&x);
	if (x==0){
		result=0;
	}
	else{
		result=1/x;
	}
	printf ("f(%.1f) = %.1f",x,result);
	return 0;
}
