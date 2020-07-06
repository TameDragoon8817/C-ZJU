void StringCount( char *s )
{
	char *p=s;
	int da=0,xiao=0,blank=0,num=0,other=0;
 
	while(*p!='\0')
	{
		if(*p>='A'&&*p<='Z')
			da++;
		else if(*p>='a'&&*p<='z')
			xiao++;
		else if(*p==' ')
			blank++;
		else if(*p>='0'&&*p<='9')
			num++;
		else
			other++;
		p++;
	}
	printf("%d %d %d %d %d",da,xiao,blank,num,other);
}