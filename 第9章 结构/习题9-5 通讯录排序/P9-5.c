#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct friend{
	char name[10];
	long int age;
	char phone[100];
};
int main(void)
{
	struct friend a[10], temp;
	int n, i, j;
	scanf("%d", &n);
	for ( i=0; i<n; i++ ) 
		scanf("%s %ld %s", a[i].name, &a[i].age, a[i].phone);
	for ( i=1; i<n; i++ ) 
		for ( j=0; j<n-i; j++ ) 
			if ( a[j].age > a[j+1].age ) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
	for ( i=0; i<n; i++ ) {
		printf("%s %ld %s\n", a[i].name, a[i].age, a[i].phone);
	}
    
    return 0;
}