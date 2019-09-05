#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_OF_NUMBER 256

int countZeros(char *number);

int main(int argc, char const *argv[]) {

  char *number = malloc(MAX_SIZE_OF_NUMBER);
  fgets(number,MAX_SIZE_OF_NUMBER,stdin);
  if ((strlen(number) > 0) && (number[strlen(number)-1] == '\n')){
    number[strlen(number)-1] = '\0';
  }

  printf("%d\n", countZeros(number));

  return 0;
}

int countZeros(char *number){
  int numberOfZeros = 0;
  int counter = 0;
  //printf("%s\n", "i got here");
  while(number[counter]!='\0'){
    if(number[counter]=='0'){
      numberOfZeros++;
    }
    counter++;
  }
  return numberOfZeros;
}
