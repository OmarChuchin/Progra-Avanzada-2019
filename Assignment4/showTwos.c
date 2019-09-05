#include <stdio.h>

int main(int argc, char const *argv[]) {
  int number;
  scanf("%d", &number);
  int boolean = 1;
  printf("%d = ",number);
  int odd;
  while (boolean) {
    if(number==2){
      boolean=0;
      printf("2\n");
      break;
    }
    odd = number & 1;
    if(odd == 0){
      printf("2 * ");
    }
    else{
      boolean=0;
      printf("%d\n", number);
    }
    number= number >> 1;
  }

  return 0;
}
