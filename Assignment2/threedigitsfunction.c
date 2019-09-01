#include <stdio.h>
#include <stdlib.h>

int actualFunction(int number){
  if(number<100){
    return number;
  }
  return number%1000;
}

int main(int argc, char const *argv[]) {
  /*-short times = 3;
  if(argc>1){
    times = atoi(argv[1]);
  }*/
  short times = 1;
  int number;
  for(short i=0;i<times;i++){
    scanf("%d", &number);
    printf("%d\n", number%1000);
  }
  return 0;
}
