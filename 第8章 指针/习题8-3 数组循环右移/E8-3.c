int ArrayShift(int a[], int n, int m)
{
    int i;
    if (m>n) {
        m = m % n;
    }
    int b[n];
    for (i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
    for (i = 0; i < n; i++)
    {
        if (i >= (n - m))
        {
            a[i + m - n] = b[i];
        }
        else
        {
            a[i + m] = b[i];
        }
    }
}