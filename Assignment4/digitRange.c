#include <stdio.h>

int main(int argc, char const *argv[]) {
  int number;
  scanf("%d", &number);

  int max=1;
  int boolean= number%(max*10);
  while(boolean!=number){
    max*=10;
    boolean= number%(max*10);
  }
  int top=0,bottom=number,temp;
  for(max;max>0;max/=10){
    temp=number/max;
    if(temp<0){
      number*=-1;
    }
    //printf("%d\n", temp);
    number=number%max;
    if(top<temp){
      top=temp;
    }
    if(bottom>temp){
      bottom=temp;
    }
  }
  //printf("%d,%d\n", top,bottom);

  printf("%d\n", top-bottom+1);
  return 0;
}
