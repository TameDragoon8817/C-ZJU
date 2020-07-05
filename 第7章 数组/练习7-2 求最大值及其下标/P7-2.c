#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int i, index, n;
	int a[9];
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	index=0;
	for(i=1; i<n; i++)
		if(a[i]>a[index])
			index=i;
			printf("%d %d", a[index], index);
			
	return 0;
}