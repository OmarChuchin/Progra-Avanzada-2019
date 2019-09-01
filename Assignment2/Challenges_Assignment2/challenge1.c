#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
  if(argc<3){
    puts("There are missing arguments");
    return 0;
  }
  int row_count = atoi(argv[1]);
  int col_count = atoi(argv[2]);
  //printf("%d\n", row_count);
  //printf("%d\n", col_count);
  int i=0,j=0;
  char string='*';
  while(j<row_count){
    if(i<col_count){
      printf("%c", string);
      i++;
    }
    else{
      printf("\n");
      i=0;
      j++;
    }
  }
  return 0;
}
