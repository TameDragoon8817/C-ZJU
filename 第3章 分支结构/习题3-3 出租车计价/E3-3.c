#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	double mile = 0;
	int time = 0;
	double price, price1, price2;
	scanf("%lf %d", &mile, &time);//注意输入格式，时间是整型
	if (mile <= 3)
	{
		price1 = 10;
	}
	else if (mile <= 10)
	{
		price1 = 10 + (mile - 3) * 2.0;
	}
	else
	{
		price1 = 10 + (10 - 3)*2.0 + (mile - 10)*3.0;
	}
	price2 = time/ 5 * 2;//等待时间费用
	price = price1 + price2;
	printf("%.0f\n", price);//结果四舍五入
	system("pause");
	return 0;
}