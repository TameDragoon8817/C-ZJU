char *search(char *s, char *t)
{
    int tlen = strlen(t);
    int cnt;
    char *p, *q;
    q = t;
    while (*s != '\0')
    {
        p = s;
        cnt = 0;

        while (*s == *t)
        {
            s++;
            t++;
            cnt++;
        }
        if (cnt >= tlen)
        {
            return p;
        }
        t = q;
        s++;
    }
    return NULL;
}