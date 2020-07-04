#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <math.h>
 
int main(){  
    int m,n;
    scanf("%d %d",&m,&n);
    int i;
    int count=0,sum=0;
    
    for(m;m<=n;m++){
        int m_1;
        m_1=sqrt(m);
        for(i=2;i<=m_1;i++){
            if(m%i==0){
                break;
            }
        }
        if(i>m_1){
            if(m==1){
                count=count;    
            }else{
                sum+=m;
                count++;
            }           
        
        }       
    }
    printf("%d %d",count,sum);   
    return 0;  
 } 