#include <stdio.h>

int main(int argc, char const *argv[]) {
  unsigned int number,shifts,MSB = 0x80000000;
  scanf("%u\n", &number);
  scanf("%u",   &shifts);

  for(int i=0;i<shifts;i++){
    int boolean = number & MSB;
    number=number<<1;
    if(boolean){
      number+=1;
    }
  }
  printf("%u\n", number);
  return 0;
}
