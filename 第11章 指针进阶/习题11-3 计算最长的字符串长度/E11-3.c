int max_len(char *s[], int n)
{
    int max = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (strlen(s[max]) < strlen(s[i]))
        {
            max = i;
        }
    }
    return strlen(s[max]);
}