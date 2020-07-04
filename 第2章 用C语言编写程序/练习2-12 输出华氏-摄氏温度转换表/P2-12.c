#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main (void)
{
	int lower,upper,fahr;
	double celsius;
	scanf ("%d%d",&lower,&upper) ;
	if (0<lower&&lower<=upper&&upper<=100)	{
	printf ("fahr celsius\n");
		for (fahr=lower;fahr<=upper;fahr=fahr+2){
		if(fahr<=upper)
		{
				celsius=5.0*(fahr-32)/9.0;
			printf("%d%6.1f\n", fahr, celsius);
			}
		}
	}
	else {
		printf ("Invalid.\n");
	}
	return 0;
 } 