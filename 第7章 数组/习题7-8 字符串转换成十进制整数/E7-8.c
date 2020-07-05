#include <stdio.h>
int main()
{
	char s[80],str[80];
	int k=0,m=0;
	int flag=1,mark;
	int num=0;
	while((s[k]=getchar())!='#')
	k++;
	s[k]='\0';
	for(int i=0;s[i]!='\0';i++)
	if((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='f')||(s[i]>='A'&&s[i]<='F'))
		{  //找出第一个十六进制字符所在的位置
			mark=i;
			break;
		}
	for(int i=0;i<mark;i++)//看看第一个十六进制字符前面有没有负号
	if(s[i]=='-')
	{  
		flag=0;
		break;	
	}
	for(int i=0;s[i]!='\0';i++)  //提取所有十六进制字符
		if((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='f')||(s[i]>='A'&&s[i]<='F'))
		{
			str[m]=s[i];
			m++;
		}
	str[m]='\0';
	for(int i=0;str[i]!='\0';i++)//将十六进制字符转换成十进制数
	{
		if(str[i]>='0'&&str[i]<='9')
		num=num*16+str[i]-'0';
		else if(str[i]>='a'&&str[i]<='f')
		num=num*16+str[i]-'a'+10;
		else if(str[i]>='A'&&str[i]<='F')
		num=num*16+str[i]-'A'+10;
	}
	if(flag==0)
	num=-num;
	printf("%d",num);

	return 0;
}