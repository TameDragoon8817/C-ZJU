#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int n, a[10][10];
	int i, j, sum=0;
	scanf("%d", &n);
	for(i=0; i<n; i++)
		for(j=0; j<n; j++){
			scanf("%d", &a[i][j]);
			if(!(i+j==n-1||i==n-1||j==n-1))
			sum+=a[i][j];
			}
	printf("%d", sum);
		
	return 0;
}