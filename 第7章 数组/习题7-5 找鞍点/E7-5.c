#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
int main (void)  
{
 
	 int n,i,j,k,l;
	 scanf("%d",&n);
	 int a[n][n];
    for(i=0; i<n; i++)  {
        for(j=0; j<n; j++)  {  
            scanf("%d",&a[i][j]);  
        }      	
    }
 
    int index=0,judge=1;
	k=0;
	l=0; 
    if(n==1){
        printf("0 0");
    }else{  
        for(i=0; i<n; i++){  
            index=i;   
            for(l=0; l<n; l++) {   
                if(a[i][k]<=a[i][l]) {
                    k=l;  
                }  
            }  
            for(j=0; j<n; j++){   
                if(a[index][k]>a[j][k]){
                    index=j;  
                    break;  
                }  
            }  
            
            if(i==index){
                judge=0;  
                break;  
            }  
        }  
        if(judge==0)	printf("%d %d",i,k);  
        else 		printf("NONE");  
    }  
    return 0;  
  
} 
/*已知问题
{
	"resource": "/f:/clone/C-ZJU/第7章 数组/习题7-5 找鞍点/E7-5.c",
	"owner": "C/C++",
	"severity": 8,
	"message": "表达式必须含有常量值",
	"startLineNumber": 8,
	"startColumn": 9,
	"endLineNumber": 8,
	"endColumn": 10
}

{
	"resource": "/f:/clone/C-ZJU/第7章 数组/习题7-5 找鞍点/E7-5.c",
	"owner": "C/C++",
	"severity": 8,
	"message": "表达式必须含有常量值",
	"startLineNumber": 8,
	"startColumn": 12,
	"endLineNumber": 8,
	"endColumn": 13
}

*/