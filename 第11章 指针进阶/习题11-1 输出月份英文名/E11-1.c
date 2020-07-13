char *getmonth(int n)
{

    static char a[12][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    if (n > 0 && n < 13)
        return &a[n - 1][0];
    else
        return NULL;
}
