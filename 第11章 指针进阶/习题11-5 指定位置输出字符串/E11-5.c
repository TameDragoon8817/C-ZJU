char *match(char *s, char ch1, char ch2)
{
    int i = 0;
    char *rtn;
    for (; (i < strlen(s)) && (s[i] != ch1); i++)
        ;
    rtn = &s[i];
    for (; i < strlen(s); i++)
    {
        printf("%c", s[i]);
        if (s[i] == ch2)
            break;
    }
    printf("\n");
    return rtn;
}