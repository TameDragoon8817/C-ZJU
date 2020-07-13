int search(int n)
{
    int i, d1, d2, d3, cnt = 0, m, a;
    for (m = 10; m <= n; m++)
    {
        for (i = 101; i <= n; i++)
        {
            if (i == m * m)
            {
                a = m * m;
                d1 = a % 10;
                d2 = a / 10 % 10;
                d3 = a / 100;
                if (d1 == d2 || d2 == d3 || d1 == d3)
                {
                    cnt++;
                }
            }
        }
    }
    return cnt;
}