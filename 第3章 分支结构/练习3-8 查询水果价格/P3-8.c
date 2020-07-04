#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(){  
    int i,j,n,a[100];  
    double price=0;  
    printf("[1] apple\n[2] pear\n[3] orange\n[4] grape\n[0] exit\n");  
    
    do{  
      scanf("%d",&a[i++]);     
    }while((getchar())!='\n');  //空格来结束scanf的读入
	 
    for(j=0;j<5&&j<i;j++){   //j<5&&j<i 小于5组数据 与小于输入的数据量组数
		if(a[j]==0){
			break;
		}  
        switch(a[j])  
        {  
            case 1:price=3;break;  
            case 2:price=2.5;break;  
            case 3:price=4.1;break;  
            case 4:price=10.2;break;  
            default:price=0.00;  
        }  
        printf("price = %.2f\n",price);  //每结束一次就打印 之前还想用数组储存相同的的值 
    }  
    return 0;  
 }