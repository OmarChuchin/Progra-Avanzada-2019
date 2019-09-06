#include <stdio.h>

int main(int argc, char const *argv[]) {
  char number[256];
  scanf("%s", &number[0]);
  int counter=0;
  int sum=0;
  char character;
  while (number[counter]!='\0') {
    //printf("%d\n", number[counter]);
    character=number[counter];
    //si lo que entra no es un numero, ignorar.
    if(character<48 || character>57){
      character=48;
    }
    //menos 48 porque el valor ascii del 0 es 48.
    sum+=character-48;
    counter++;
  }
  printf("%d\n", sum);
  return 0;
}
