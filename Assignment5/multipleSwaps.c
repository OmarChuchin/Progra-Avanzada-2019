#include <stdio.h>

unsigned int swapBits(int number,int a,int b){
  unsigned int aBit = 1, bBit = 1;

  aBit = aBit << a;
  bBit = bBit << b;

  if(aBit & number){
    if(bBit & number){
      //printf("%u\n", number);
      return number;
    }
    else{
      number+=bBit;
      number-=aBit;
    }
  }
  else{
    if(bBit & number){
      number+=aBit;
      number-=bBit;
    }
  }
  return number;
}

int main(int argc, char const *argv[]) {

  unsigned int number,a,b;
  scanf("%u\n", &number);
  scanf("%u\n", &a);
  scanf("%u",   &b);

  while (a<b){
    number=swapBits(number,a,b);
    a++;b--;
  }

  printf("%u\n", number);
  return 0;

  return 0;
}
