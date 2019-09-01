#include <stdio.h>

int mantra(int total){
  int i=0;
  char string[]="There's one thing every coder must understand:\nThe printf command.\n  ";
  while(i<total){
    printf("%s\n", string);
    i++;
  }
  return 0;
}

int main(){
  mantra(2);
  return 0;
}
