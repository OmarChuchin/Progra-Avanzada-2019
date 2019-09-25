#include <stdio.h>
#define SIZE 255

int maxValue(int* arr,int arraySize){
  int result = arr[0];
  for(int i=1;i<arraySize;i++){
    if(result<arr[i]){
      result = arr[i];
    }
  }
  return result;
}

int minValue(int* arr,int arraySize){
  int result = arr[0];
  for(int i=1;i<arraySize;i++){
    if(result>arr[i]){
      result = arr[i];
    }
  }
  return result;
}

int main(int argc, char const *argv[]) {
  int h[SIZE] = {0};
  unsigned char paramSize;

  scanf("%hhu", &paramSize);

  for(int i=0;i<paramSize;i++){
    scanf("%d", &h[i]);
  }

  printf("%d\n", maxValue(&h[0],paramSize)-minValue(&h[0],paramSize)+1);

  return 0;
}
