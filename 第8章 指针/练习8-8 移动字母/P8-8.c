void Shift( char s[] )
{
    char a[3];
    int i,j;
    for(i = 0; i < 3;i++)
        a[i] = s[i];
    for(i=3;s[i]; i++)
        s[i-3]=s[i];
    for(j=i-3, i = 0; i < 3;i++)
        s[j++] = a[i];
}