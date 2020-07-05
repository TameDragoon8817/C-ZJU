#include<stdio.h>  
int main()  
{  
    char str[1001];  
    gets_s(str,1000);  
    int count=0;  
    int i=0;  
    while(str[i]==' ') //跳过开头的空格  
        i++;  
      
    while(str[i]!='\0')  
    {  
        if(str[i]!=' ')  
        {   
            count++;  
            while(str[i]!=' ') //跳过一个单词的其他字符  
            {  
                if(str[i]=='\0')  //这句很重要，漏掉后出现严重错误  
                    break;  
                i++;      
            }  
        }  
        else  
        {  
            while(str[i]==' ' )  
                i++;      
        }  
    }  
    printf("%d\n",count);  
}