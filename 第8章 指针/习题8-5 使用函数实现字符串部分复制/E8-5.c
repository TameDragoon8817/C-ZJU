void strmcpy( char *t, int m, char *s )
{
    int i;
    char temp[MAXN-m+1];
    int n = strlen(t);
    if (m>n) {
        *s = NULL;
    }
    else
    {
        for (i = m - 1; i <= n - 1;i++)
        {
            s[i - (m - 1)] = t[i];
        }
    }
}