#include <stdio.h>
#define SIZE 255

unsigned char rangeCount(int* arr,int arraySize,int minValue,int maxValue){
  unsigned char result = 0;
  for (unsigned char i = 0; i < arraySize; i++) {
    if(minValue<=arr[i] && arr[i]<=maxValue){
      result++;
    }
  }
  return result;
}

int main(int argc, char const *argv[]) {
  int h[SIZE] = {0}, maxValue,minValue;
  unsigned char paramSize;

  scanf("%d", &minValue);
  scanf("%d", &maxValue);
  scanf("%hhu", &paramSize);

  for(int i=0;i<paramSize;i++){
    scanf("%d", &h[i]);
  }

  printf("%hhu\n", rangeCount(&h[0],paramSize,minValue,maxValue));

  return 0;
}
