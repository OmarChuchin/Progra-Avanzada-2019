#include <stdio.h>

int main(int argc, char const *argv[]) {

  unsigned int number,a,b;
  scanf("%u\n", &number);
  scanf("%u\n", &a);
  scanf("%u",   &b);

  unsigned int aBit = 1;
  for(int i=0;i<a;i++){
    aBit = aBit << 1;
  }
  unsigned int bBit = 1;
  for(int i=0;i<b;i++){
    bBit = bBit << 1;
  }
  if(aBit & number){
    if(bBit & number){
      printf("%u\n", number);
      return 0;
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
  printf("%u\n", number);
  return 0;

  return 0;
}
