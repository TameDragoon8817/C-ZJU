#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main (void)
{
  double x, rs=1, a, up=1; scanf("%lf", &x);
  double down=1; 
  for(int i=1; ; i++)
  {
    up*=x;
    down*=i;
    a=up/down;
    rs+=a;
    if(a<0.00001) break;
  }
  printf("%.4f\n", rs);
  return 0;
}