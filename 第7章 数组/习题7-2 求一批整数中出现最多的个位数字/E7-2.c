#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAXN 10
 
int main(void) {
	int n, number, index, Times, i;
	int a[MAXN] = {0};
	
	scanf("%d", &n);
	for ( i=0; i<n; i++ ) {
		scanf("%d", &number);
		while ( number ) {
			index = number % 10;
			a[index]++;
			number = number / 10;
		}
	}
	
	Times = 0;
	for ( i=0; i<MAXN; i++ ) 
		if ( Times < a[i] )
			Times = a[i];
	printf("%d:", Times);
	
	for ( i=0; i<MAXN; i++ ) 
		if ( Times == a[i] )
			printf(" %d", i);
	
	return 0;
}