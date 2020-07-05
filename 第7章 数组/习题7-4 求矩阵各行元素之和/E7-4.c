#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
int main (void)
{  
	 int m,n,i,j,k;
	 scanf("%d %d",&m,&n);
	 int a[m][n];
	 int b[100]={0};
	 for(i=0;i<m;i++){
	 	for(j=0;j<n;j++){
	 		scanf("%d",&a[i][j]);
	 	}
	 }
	k=0;
	 for(i=0;i<m;i++){
	 	for(j=0;j<n;j++){
	 		b[k]+=a[i][j];
	 	}
	 	k++;
	 }
	for(i=0;i<m;i++){
		printf("%d\n",b[i]);	
	}
	return 0;  
} 