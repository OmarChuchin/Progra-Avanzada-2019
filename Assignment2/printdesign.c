#include <stdio.h>

int MAX = 10;

int main(int argc, char const *argv[]) {
  int signs = 5;
  for(int limit=1;limit<MAX;limit+=2){

    for(int i=0;i<signs;i++){
      printf("%c", '-');
    }
    for(int i=0;i<limit;i++){
      printf("%d", limit);
    }
    for(int i=0;i<signs;i++){
      printf("%c", '-');
    }
    printf("\n");
    signs--;
  }

  return 0;
}
