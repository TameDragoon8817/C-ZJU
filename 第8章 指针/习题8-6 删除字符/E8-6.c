void delchar(char *str, char c)
{
    int i, j, t = 1;
    for (i = MAXN - 1; i >= 0; i--)
    {
        if (str[i] == c)
        {
            for (j = i; j < MAXN - t; j++)
            {
                str[j] = str[j + 1];
            }
            t++;
        }
    }
}