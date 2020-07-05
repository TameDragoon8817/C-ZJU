#include <stdio.h>  
int main (void)  
{
	char a[80];
	int d,i,j,k;
	i=0;
	while((d=getchar())!='\n'){
		a[i]=(char)d;
		i++;
	}
	a[i]='\0';
	
	k=0;
	for(j=0;j<i;j++){
		if(a[j]>='A'&&a[j]<='Z'&&a[j]!='A'&&a[j]!='E'&&a[j]!='I'&&a[j]!='O'&&a[j]!='U'){
			k++;	
		}
	}
	printf("%d",k);
    return 0; 
}