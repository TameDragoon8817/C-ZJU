int fib(int n){
    int a, b, c;
    a = 1;
    b = 1;
    if (n == 1)
    {
        return 1;
    }
    else
    {
        if (n == 2)
        {
            return 1;
        }
        else
        {
            for (int i = 3; i <= n; i++)
            {
                c = a + b;
                a = b;
                b = c;
            }
            return b;
        }
    }
}

void PrintFN(int m, int n)
{
    int i = 1;
    int count = 0;
    while (fib(i) <= n)
    {
        if (fib(i) >= m)
        {
            count++;
            if (count == 1)
            {
                printf("%d", fib(i));
            }
            else
            {
                printf(" %d", fib(i));
            }
        }
        i++;
    }
    if (count == 0)
    {
        printf("No Fibonacci number\n");
    }
}