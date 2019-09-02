#include <stdio.h>

int printSquare(int bottom,int top);

int main(int argc, char const *argv[]) {
  int top,bottom;
  scanf("%d\n", &bottom);
  scanf("%d", &top);
  printSquare(bottom,top);
  return 0;
}

int printArray(int *array){
  printf("[");
  int length = sizeof(array);
  for(int i=0;i<length;i++){
    if(i<length-1){
      printf("%d,",array[i] );
    }
    else{
      printf("%d",array[i] );
    }
  }
  printf("]\n");
  return 0;
}

int printArray2(int *array,int length){
  for(int i=0;i<length;i++){
    printf("%d",array[i]);
  }
  printf("\n");
  return 0;
}

int printSquare(int bottom,int top){
  int length = top-bottom+1;
  int row[length];
  for(int i=0;i<length;i++){
    row[i]=bottom+i;
  }
  int i=0;
  while (i<length) {
    printArray2(&row[0],length);
    for(int i=0;i<length;i++){
      if(row[i]==top){
        row[i]=bottom;
      }
      else{
        row[i]++;
      }
    }
    i++;
  }
  return 0;
}
