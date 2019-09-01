#include <stdio.h>


int main(int argc, char const *argv[]) {
  short counter=1;
  for(short i=0;i<60;i++){
    if(counter==9){
      printf("|");
      counter=-1;
    }
    else{
      printf(" ");
    }
    counter++;
  }
  printf("\n");
  counter = 1;
  for(short i=0;i<60;i++){
    printf("%d", counter);
    if(counter==9){
      counter=-1;
    }
    counter++;
  }
  printf("\n");
  return 0;
}
