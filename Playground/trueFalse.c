#include <stdio.h>

int test(){
  return 1;
}

int main(int argc, char const *argv[]) {
  if(test()){
    printf("True\n");
  }
  else{
    printf("False\n");
  }
  return 0;
}
