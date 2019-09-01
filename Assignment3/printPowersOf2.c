#include <stdio.h>

int printPowers(int top);
int power(int number,int times);

int main(int argc, char const *argv[]) {
  int number;
  scanf("%d", &number);
  return printPowers(number);
}

int power(int number,int times){
  if(times<1){
    return 1;
  }
  return power(number,times-1)*number;
}

int printPowers(int top){
  if (top<0){
    return 1;
  }
  for(int i=0;i<=top;i++){
    if(i<top){
      printf("%d ", power(2,i));
    }
    else{
      printf("%d\n", power(2,i));
    }
  }
  return 0;
}
