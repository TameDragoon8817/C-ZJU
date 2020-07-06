int reverse(int number)
{
    int t=0;
    while(number!=0)
    {
        t=t*10+number%10;
        number=number/10;
    }
    return t;
}