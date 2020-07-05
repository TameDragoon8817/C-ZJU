#include<stdio.h>
#include<string.h>
int main(void)
{
	int i, cnt=0;
	char ch;
	char str1[80];
	char str2[80];
	ch = getchar();
	for (i = 0; ch != '\n'; i++)
	{
		str1[i] = ch;
		cnt++;
		ch = getchar();
	}
 
	for (i = 0; i < cnt; i++)
	{
		if (str1[i] >= 'A' && str1[i] <= 'Z')
		{
			str2[i] = 'A' + 'Z' - str1[i];
		}
		else
		{
			str2[i] = str1[i];
		}
	}
	for (i = 0; i < cnt; i++)
		printf("%c",str2[i]);
	return 0;
}
