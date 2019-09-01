#include <stdio.h>

int printStrings(char *string,int times);

int main(int argc, char const *argv[]) {
  char *string;
  int times;
  scanf("%d\n",&times);
  scanf("%s\n", string);
  printStrings(string,times);
  return 0;
}

int printStrings(char *string,int times){
  for(int i=0;i<times;i++){
    printf("%s", string);
  }
  printf("\n");
  return 0;
}
