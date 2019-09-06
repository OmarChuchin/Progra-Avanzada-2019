#include <stdio.h>

#define TEN 10

int howManyDigits(int number){
  int result = 1;
  int digits = 1;
  int boolean = number%(result*10);
  while(boolean!=number){
    result*=10;
    digits++;
    boolean = number%(result*10);
  }
  return digits;
}

int ppow(int number,int power){
  if(power<1){
    return 1;
  }
  power--;
  return ppow(number,power)*number;
}

int main(int argc, char const *argv[]) {
  unsigned int number;
  scanf("%u", &number);


  unsigned int numberOfDigits = howManyDigits(number);
  unsigned int result=0;
  unsigned int divider;
  int temp=0;
  //In case the number of digits is odd.
  if(numberOfDigits%2==1){
    divider = ppow(TEN,numberOfDigits-1);
    //printf("%u\n", divider);
    temp=(number/divider)*divider;
    result+=temp;
    number-=temp;
    numberOfDigits--;
  }
  // printf("%u\n", result);
  // printf("%u\n", number);
  //printf("%u\n", numberOfDigits);
  int temp2=0;
  unsigned int divider2;
  for(numberOfDigits;numberOfDigits>0;numberOfDigits-=2){
    divider=ppow(TEN,numberOfDigits-1);
    divider2=ppow(TEN,numberOfDigits-2);
    temp2=(number/divider)*divider;
    // printf("%s\n", "Dividers: ");
    // printf("%d\n", divider);
    // printf("%d\n", divider2);
    number-=temp2;
    // printf("%s\n", "Variables: ");
    temp=(number/divider2)*divider2;
    // printf("%d\n", temp);
    // printf("%d\n", temp2);
    // //printf("%d\n", temp);
    number-=temp;
    result+=temp*10+temp2/10;
  }
  printf("%u\n", result);

  return 0;
}
