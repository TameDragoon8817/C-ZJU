#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main (void)
{
	int score;
	scanf("%d", &score);
	if (score>=90){
		putchar('A');
	}
	else if (score>=80){
		putchar('B');
	}
	else if (score>=70){
		putchar('C');
	}
	else if (score>=60){
		putchar('D');
	}
	else{
		putchar('E');
	}
	return 0;
}