#include <stdio.h>

int main(int argc, char const *argv[]) {
  for(int i=0;i<3;i++){
    for(int j=0;j<10;j++){
      for(int k=0;k<3;k++){
        printf("%d", j);
      }
    }
    printf("\n");
  }
  return 0;
}
