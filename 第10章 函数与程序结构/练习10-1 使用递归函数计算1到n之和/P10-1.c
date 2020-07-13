int sum(int n)
{
    int result;
    if (n <= 0)
        return 0;
    else
    {
        if (n == 1)
        {
            result = 1;
        }
        else
            result = n + sum(n - 1);
        return result;
    }
}