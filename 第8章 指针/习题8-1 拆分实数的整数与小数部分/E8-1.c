void splitfloat( float x, int *intpart, float *fracpart )
{
    *intpart = x / 1;
    *fracpart =x-*intpart;
}