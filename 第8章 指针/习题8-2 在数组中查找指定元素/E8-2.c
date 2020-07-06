int search(int list[], int n, int x)
{
    int index, i, judge=0;
    for (i = 0; i < n; i++)
        if (list[i] == x)
        {
            index = i;
            judge = 1;
            break;
        }
    if (judge != 1)
    {
        index = -1;
    }
    return index;
}