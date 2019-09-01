#include <stdio.h>

int MAX = 22;

int main(int argc, char const *argv[]) {
  for(int limit=0;limit<12;limit+=2){
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
