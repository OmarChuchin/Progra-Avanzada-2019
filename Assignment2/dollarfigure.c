#include <stdio.h>

int MAX = 28;

int main(int argc, char const *argv[]) {

  for(int i=7;i>0;i--){
    for(int j=0;j<(7-i)*2;j++){
      printf("%c", '*');
    }
    for(int j=0;j<i;j++){
      printf("%c", '$');
    }
    for(int j=0;j<i*2;j++){
      printf("%c", '*');
    }
    for(int j=0;j<i;j++){
      printf("%c", '$');
    }
    for(int j=0;j<(7-i)*2;j++){
      printf("%c", '*');
    }
    printf("\n");
  }
  return 0;
}
