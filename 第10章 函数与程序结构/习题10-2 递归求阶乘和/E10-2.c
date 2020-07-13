double fact (int n)
{
    double result;
    if (n==1||n==0) {
        result = 1;
    }
    else {
        result = n * fact(n - 1);
    }
    return result;
}
double factsum( int n )
{
    int i;
    double result;
    for (i = 1; i <= n;i++)
    {
        result = result + fact(i);
    }
    return result;
}