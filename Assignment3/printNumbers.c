#include <stdio.h>

int printNumbers(int top);

int main(int argc, char const *argv[]) {
  int number;
  scanf("%d", &number);
  return printNumbers(number);
}

int printNumbers(int top){
  if (top<1){
    return 1;
  }
  for(int i=1;i<=top;i++){
    if(i<top){
      printf("[%d] ", i);
    }
    else{
      printf("[%d]\n", i);
    }
  }
  return 0;
}
