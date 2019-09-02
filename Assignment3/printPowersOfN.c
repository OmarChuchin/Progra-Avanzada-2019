#include <stdio.h>

int printPowers(int top,int number);
int power(int number,int times);

int main(int argc, char const *argv[]) {
  int number,times;
  scanf("%d", &number);
  scanf("%d", &times);
  return printPowers(times,number);
}

int power(int number,int times){
  if(times<1){
    return 1;
  }
  return power(number,times-1)*number;
}

int printPowers(int top,int number){
  if (top<0){
    return 1;
  }
  for(int i=0;i<=top;i++){
    if(i<top){
      printf("%d ", power(number,i));
    }
    else{
      printf("%d\n", power(number,i));
    }
  }
  return 0;
}
