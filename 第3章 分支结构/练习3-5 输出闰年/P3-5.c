#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int year, i, count=0;
	scanf("%d", &year);
	if(year<=2000||year>2100)
		printf("Invalid year!\n");
	else{
		for(i=2001; i<=year; i++){
			if(i%4==0&&i%100!=0||i%400==0){
				printf("%d\n", i);
				count++;
			}
		}
		if(count==0)
			printf("None\n");
	}	
	return 0;
 }