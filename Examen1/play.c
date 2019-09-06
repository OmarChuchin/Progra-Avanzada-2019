#include <stdio.h>

int main(int argc, char const *argv[]) {
  unsigned short counter=3;
  for(char i=0;i<18;i++){
    printf("%hu\n", counter);
    counter*=4;
    if(counter==0){
      counter=3;
    }
  }
  return 0;
}
