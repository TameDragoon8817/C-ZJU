#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main (void)
{
	int n=0,i,j;
	scanf("%d",&n);
	int row=(n/2)+1;
	for(i=1;i<=row;i++){
		for(j=row-i;j>0;j--){
			printf("  ");
		}
	for(j=0;j<(2*i-1);j++){
		printf("* ");
		}
	printf("\n");
	}
	for(i=1;i<row;i++){
		for(j=0;j<i;j++){
			printf("  ");
			}
	for(j=(row-i)*2-1;j>0;j--){
		printf("* ");
		}
		printf("\n");
	}
	return 0;
}