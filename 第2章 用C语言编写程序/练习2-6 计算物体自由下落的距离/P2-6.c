#include<stdio.h>
#include<math.h>
int main (void)
{
	double height;
	int t,g;
	t=3;
	g=10;
		height=g*pow(t,2)/2;
	if (height<=100){
		height=g*pow(t,2)/2;
	}
	else{
		height=100;
	}
	printf ("height = %.2f",height);
	return 0;
}
