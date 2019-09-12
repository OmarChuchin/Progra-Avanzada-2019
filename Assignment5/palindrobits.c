#include <stdio.h>

int main(int argc, char const *argv[]) {

  int number;
  scanf("%d", &number);

  unsigned int FSB= 0x80000000;
  char boolean =1;
  char firstBit;
  for(firstBit = 32;boolean>0;firstBit--){
    if(number & FSB){
      boolean--;
    }
    else{
      FSB=FSB>>1;
    }
  }
  //printf("%u\n", firstBit);

  unsigned int counterBit = 1;
  unsigned int temp = 0;
  for(char i=0;i<=firstBit;i++){
    if(FSB & number){
      temp+=counterBit;
    }
    counterBit=counterBit<<1;
    FSB=FSB>>1;
  }

  //printf("%u,%u\n", number,temp);
  if(number==temp){
    printf("%u\n", 1);
  }
  else{
    printf("%u\n", 0);
  }
  return 0;
}
