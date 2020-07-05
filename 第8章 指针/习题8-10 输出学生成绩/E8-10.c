#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main (void)
{
  	int N,grade,k,i=1;
  	float average,max,min,sum=0.0;
  	float maxy(float x,float y);
 	float miny(float x,float y);
	scanf("%d",&N);
	for(k=0;k<N;k++){
    	scanf("%d",&grade);
    	sum=sum+grade;
   		if (i==1){
		   	max=grade;
    		min=grade;
     		i--;
   		}		
    	max=maxy(max,grade);
    	min=miny(min,grade);
	}
  	average=sum/N;
  	printf("average = %.2f\nmax = %.2f\nmin = %.2f",average,max,min);
  return 0;
}
float maxy(float x,float y){
 	float z;
 	if(x>y)
	z=x;
	else
	z=y;
	return(z);
}
float miny(float x,float y){
 	float z;
 	if(x<y)
 	z=x;
	else
 	z=y;
 	return(z);
}