#include "stdio.h"

#define Gauss(x) (x*(x+1))/2

int sum(int low,int high){
  low--;
  int bottom = Gauss(low);
  //printf("%d\n", bottom);
  int top = Gauss(high);
  //printf("%d\n", top);
  return top-bottom;
}

int main(void) {
  printf("low? ");
  int low;
  scanf("%d", &low);
  //printf("%d\n", Gauss(low-1)); << dont do this.
  printf("high? ");
  int high;
  scanf("%d", &high);

  printf("sum = %d\n", sum(low,high));

  return 0;
}
