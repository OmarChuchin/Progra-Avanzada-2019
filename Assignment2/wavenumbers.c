#include <stdio.h>
#include <stdlib.h>

int STANDARD = 40;

int printline(int length);
int printwave(int length);
int printnumbers(int length);

int main(int argc, char const *argv[]) {

  int length;
  if(argc>1){
    length = atoi(argv[1]);
  }
  else{
    length = STANDARD;
  }

  printline(length);
  printwave(length);
  printnumbers(length);
  printline(length);

  return 0;
}

int printline(int length){
  char c = '-';
  for(int i=0;i<length;i++){
    printf("%c", c);
  }
  printf("\n");
  return 0;
}

int printwave(int length){
  char c[] = {'_','-','^'};
  short iter = 0;
  for(int i=0;i<length;i++){
    switch (iter) {
      case 3:
        printf("%c", c[1]);
        iter=0;
        break;
      default:
        printf("%c", c[iter]);
        iter++;
    }
  }

  printf("\n");
  return 0;
}

int printnumbers(int length){

  short bit = 0;
  short number=1;
  for(int i=0;i<length;i++){
    if(bit>1){
      bit=0;
      number++;
    }
    if(number>9){
      number=0;
    }
    printf("%d",number);
    bit++;
  }

  printf("\n");
  return 0;
}
