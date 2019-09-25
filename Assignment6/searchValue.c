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

unsigned char binarySearch(int* arr,int arraySize,int objective){
  bubbleSort(arr,arraySize);
  char a = 0, z=arraySize-1;
  if(arr[a]==objective){
    return a;
  }
  if(arr[z]==objective){
    return z;
  }
  int middle = (a+z)/2, boolean = 1;
  while(middle>a && middle<z && boolean){
    middle = (a+z)/2;
    if(arr[middle]==objective){
      boolean = 0;
    }
    else if(objective>middle){
      a=middle;
    }
    else{
      z=middle;
    }
  }
  return middle;
}

int main(int argc, char const *argv[]) {
  unsigned int h[SIZE] = {0}, objective;
  unsigned char paramSize;

  scanf("%hhu", &paramSize);
  scanf("%u", &objective);

  for(int i=0;i<paramSize;i++){
    scanf("%u", &h[i]);
  }

  printf("%hhu\n", binarySearch(&h[0],paramSize,objective));

  return 0;
}
