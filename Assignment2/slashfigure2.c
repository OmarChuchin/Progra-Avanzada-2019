#include <stdio.h>
#include <stdlib.h>

int MAX;

int pyramid(int size);

int main(int argc, char const *argv[]) {
  int number;
  scanf("%d", &number);
  pyramid(number);
  return 0;
}

int pyramid(int size){
  MAX = (size-1)*2*2+2;
  for(int limit=0;limit<size*2;limit+=2){
    int signs = MAX-limit*2;
    for(int i=0;i<limit;i++){
      printf("%s", "\\");
    }
    for(int i=0;i<signs;i++){
      printf("%c", '!');
    }
    for(int i=0;i<limit;i++){
      printf("%c", '/');
    }
    printf("\n");
    signs--;
  }
  return 0;
}
