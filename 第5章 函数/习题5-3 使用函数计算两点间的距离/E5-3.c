double dist( double x1, double y1, double x2, double y2 )
{
    double result, pow1, pow2;
    pow1 = (pow(fabs(x2 - x1),2));
    pow2 = (pow(fabs(y2 - y1),2));
    result = sqrt(pow1 + pow2);
    return result;
}