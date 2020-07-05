#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct book{
  char name[31];
  double price;
};
int main(){
  struct book book1[10];
  int i,n,max1,min1;
  double max=-1,min=1000000;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("\n");
    gets_s(book1[i].name,30);
    scanf("%lf",&book1[i].price);
  }
  for(i=0;i<n;i++){
    if(book1[i].price>max){
    max=book1[i].price;
      max1=i;
    }
    if(book1[i].price<min){
      min=book1[i].price;
      min1=i;
    }
  }
  printf("%.2lf, %s\n",book1[max1].price,book1[max1].name);
  printf("%.2lf, %s\n",book1[min1].price,book1[min1].name);
return 0;
}