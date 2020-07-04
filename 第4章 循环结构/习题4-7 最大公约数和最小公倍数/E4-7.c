#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <math.h>
 
int main(void)
{
	int m,n;
	scanf("%d %d",&m,&n);
	int yushu;
	yushu=m%n;
	int  x;
	x=m*n;
	if(yushu==0){
		printf("%d %d",n,x/n);
	}else{
		while(yushu!=0){
			m=n;
			n=yushu;
			yushu=m%n;		 
		}
		printf("%d %d",n,x/n);
	}					         
    return 0;  
 } 