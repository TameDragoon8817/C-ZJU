int fn( int a, int n )
{
    int result=a, i;
    for (i = 2; i <= n;i++)
        result = result * 10 + a;
    return result;
}

int SumA( int a, int n )
{
    int item, sum=0, i;
    for (i = 1; i <= n;i++)
    {
        item = fn(a, i);
        sum = sum + item;
    }
    return sum;
}