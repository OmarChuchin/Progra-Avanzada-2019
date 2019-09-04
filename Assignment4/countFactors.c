#include <stdio.h>

int countFactors(int number){
  int factorCounter=1;
  for(int i=2;i<=number;i++){
    if(number%i==0){
      factorCounter++;
    }
  }
  return factorCounter;
}

int main(int argc, char const *argv[]) {
  int number;
  scanf("%d", &number);
  printf("%d\n", countFactors(number));
  return 0;
}
