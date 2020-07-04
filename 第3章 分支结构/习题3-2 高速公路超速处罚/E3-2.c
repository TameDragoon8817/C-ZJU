#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
  int speed,limit;
  double x;
  scanf("%d %d",&speed,&limit);
  x=(double)(speed-limit)/limit;
  if(speed<=limit||x<0.1)
  {
    printf("OK");
  }
  else if(x>=0.1&&x<0.5){
    printf("Exceed %.0f%%. Ticket 200",100*x);
  }
  else{
    printf("Exceed %.0f%%. License Revoked",100*x);
  }
  return 0;
}