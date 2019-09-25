#include "stdio.h"
#define SIZE 100

int sorter(int* arr, int arraySize){
  for(int i=0;i<arraySize-1;i++){
    for(int j=i+1;j<arraySize;j++){
      if(arr[i]>arr[j]){
        int temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      }
    }
  }
  return 0;
}

int main(void) {
  unsigned int h[SIZE] = {0};
  unsigned char paramSize;

  scanf("%hhu", &paramSize);

  for(int i=0;i<paramSize;i++){
    scanf("%u", &h[i]);
  }

  sorter(&h[0],paramSize);


  if(paramSize%2!=0){
    printf("%u\n", h[paramSize/2]);
  }
  else{
    double result = (h[paramSize/2-1]+h[paramSize/2])/2.0;
    printf("%.1f\n", result);
  }

  return 0;
}
