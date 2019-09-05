#include <stdio.h>

int xo (int size);

int main(int argc, char const *argv[]) {
  int size;
  scanf("%d", &size);
  if(size<0){
    printf("%s\n", "There is something wrong");
    return 1;
  }
  xo(size);
  return 0;
}

int xo(int size){
  int relativeSize=size-1;
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      if(j==i || (relativeSize-j)==i){
        printf("x");
      }
      else{
        printf("o");
      }
    }
    printf("\n");
  }
}
