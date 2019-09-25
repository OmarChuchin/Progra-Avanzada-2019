#include <stdio.h>
#define SIZE 100

int bubbleSort(int* arr,int arraySize){
  for(int i=arraySize;i>0;i--){
    for(int j=0;j<i-1;j++){
      if(arr[j+1]<arr[j]){
        unsigned int temp = arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
      }
    }
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  unsigned int h[SIZE] = {0};
  unsigned char paramSize;

  scanf("%hhu", &paramSize);

  for(int i=0;i<paramSize;i++){
    scanf("%u", &h[i]);
  }

  bubbleSort(&h[0],paramSize);

  for(int i=0;i<paramSize;i++){
    printf("%u\n", h[i]);;
  }

  return 0;
}
