double calc_pow(double x, int n)
{
    int result;
    if (n == 1)
        result = x;
    else
        result = x * calc_pow(x, n - 1);
    return result;
}