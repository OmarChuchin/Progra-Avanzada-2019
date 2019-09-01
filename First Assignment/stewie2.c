#include <stdio.h>

int bloody_Hell(int number){
  char stewie[]="|| Victory is mine! ||";
  //CAUSE SHE IS STILL THE UGLIEST
  char meg[]="\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
  int i=0;
  while(i<number){
    printf("%s\n", stewie);
    printf("%s\n", meg);
    i++;
  }
  return 0;
}

int main(){
  printf("%s\n","//////////////////////");
  bloody_Hell(5);
  return 0;
}
