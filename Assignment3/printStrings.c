#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_STRING 256

int printStrings(char *string,int times);

int main(int argc, char const *argv[]) {

  char *string = malloc(SIZE_OF_STRING);
  int times;

  scanf("%d\n",&times);
  fgets(string, SIZE_OF_STRING, stdin);

  if ((strlen(string) > 0) && (string[strlen(string)-1] == '\n')){
    string[strlen(string)-1] = '\0';
  }

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
