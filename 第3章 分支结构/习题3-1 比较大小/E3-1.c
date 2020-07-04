#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>  
int main (void)
{  
   	int a,b,c;
   	int temp;
   	scanf("%d %d %d",&a,&b,&c);
	if(a>b){
		a=a;
	}else{
		temp=a;
		a=b;
		b=temp;
	}
	if(a>c){
		a=a;
	}else{
		temp=a;
		a=c;
		c=temp;
	}
	if(b>c){
		b=b;
	}else{
		temp=b;
		b=c;
		c=temp;
	}	
	
	printf("%d->%d->%d",c,b,a);
    return 0;  
 }
