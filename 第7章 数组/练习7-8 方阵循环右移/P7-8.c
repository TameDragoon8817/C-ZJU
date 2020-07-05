#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int t[2][13]= {{0,31,28,31,30,31,30,31,31,30,31,30,31},
               {0,31,29,31,30,31,30,31,31,30,31,30,31} 
};
int year(int x); 
int day(int y,int m,int d );
int main()  {  
       int y,m,d,sum;
       scanf("%d/%d/%d",&y,&m,&d);
       sum=day(y,m,d);
       printf("%d",sum);
       return 0;  
} 
int year(int x){
        return (x%4==0&&x%100!=0)||(x%400==0);
}
int day(int y,int m,int d ){
    int k=0,i=0,count=0;
    if (year(y)){
        	k=1;
    }
    for(count=0,i=0;i<m;i++){
    	count+=t[k][i];
    }
    	count+=d;
    return count;
}