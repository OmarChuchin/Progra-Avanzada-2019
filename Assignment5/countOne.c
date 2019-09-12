#include <stdio.h>

int main(int argc, char const *argv[]) {
  int number;
  scanf("%d", &number);

  int bitCounter=1;
  int counter=0;
  int result = 0;
  while (counter<32) {
    if(bitCounter & number){
      result++;
    }
    counter++;
    bitCounter= bitCounter<<1;
  }
  printf("%u\n", result);
  return 0;
}
