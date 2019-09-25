#include "stdio.h"
#define SIZE 100

unsigned int min(int* arr, int arrSize){
  unsigned int result = arr[0];
  for (int i=1;i<arrSize;i++) {
    if(arr[i]<result){
      result=arr[i];
    }
  }
  return result;
}


int main(void) {
  unsigned int h[SIZE] = {0};
  unsigned char paramSize;

  scanf("%hhu", &paramSize);

  for(int i=0;i<paramSize;i++){
    scanf("%u", &h[i]);
  }

  printf("%u\n", min(&h[0],paramSize));

  return 0;
}
