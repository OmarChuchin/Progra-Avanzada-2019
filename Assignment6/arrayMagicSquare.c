#include <stdio.h>
#define SIZE 255

unsigned char isMagic(int* arr,int arraySize){
  int result = 0;
  for (unsigned char i = 0; i < arraySize; i++) {
    result += arr[i];
  }

  int temporal_result = 0;
  for(unsigned char i = 1; i < arraySize; i++){
    for(unsigned char j = 0; j < arraySize;j++){
      temporal_result += arr[i*arraySize+j];
    }
    if(temporal_result!= result){
      return 0;
    }
    temporal_result = 0;
  }
  return 1;
}

int main(int argc, char const *argv[]) {
  int h[SIZE] = {0}, maxValue,minValue;
  unsigned char paramSize;

  scanf("%hhu", &paramSize);

  for(int i=0;i<paramSize;i++){
    for(int j=0;j<paramSize;j++){
    scanf("%d", &h[i*paramSize+j]);
    }
  }

  if(isMagic(&h[0],paramSize)){
    printf("true\n");
  }
  else{
    printf("false\n");
  }

  return 0;
}
