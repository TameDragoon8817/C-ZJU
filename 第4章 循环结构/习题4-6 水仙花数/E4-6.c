#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int p(int a,int b);
int main()
{
	int N;
	scanf("%d",&N);
	
	int i,j,count,trans,sum=0,flag=0;		 // flag为0的时候不输出回车，目的是为了满足题目格式 
	
	for(i= p(10,N-1);i<p(10,N);i++){    //定义了i的取值范围，一定是在 10^N-1到10^N之间取值；
		trans=i;  
		sum=0;
		j= 1;
		while(j<= N){				//取余然后算sum 
			sum+=p(trans%10, N);		//取出最后一位然后N次方 
			trans/=10;						//丢掉最后一位 .
			j++;
			if(sum==i&&trans==0){
			printf("%d\n",i);
			flag=1;			
				break;
			}
		}
	}
	
	return 0; 
}
int p(int a,int b)
{
 int t=a;
 for(int i=1;i<b;i++)
  a=a*t;
  
 return a;
}