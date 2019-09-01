#include <stdio.h>

int length(char *string){
  int i=0;
  short True = 1;
  while(True){
    if(string[i+1]=='\0'){
      True=0;
    }
    i++;
  }
  return i;
}


int main(int argc, char const *argv[]) {
  char *string = argv[1];
  printf("%d\n", length(string));
  return 0;
}
