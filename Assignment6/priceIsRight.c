#include <stdio.h>
#include <stdlib.h>
#define SIZE 255

unsigned int absDistance(int point,int price){
  if(point>price){
    return -1;
  }
  return price-point;
}

int main(int argc, char const *argv[]) {

  // if(argc<3){
  //   return 1;
  // }

  // int price = atoi(argv[1]);
  // unsigned char paramSize = atoi(argv[2]);

  int price; scanf("%d", &price);
  unsigned char paramSize; scanf("%hhu", &paramSize);

  int array[SIZE];
  for(unsigned char i = 0; i<paramSize;i++){
    scanf("%d", &array[i]);
  }

  int distance = 1000000, result = -1;
  for(unsigned char i = 0; i<paramSize;i++){
    int testDistance = absDistance(array[i],price);
    if(testDistance==0){
      result = price;
      i = paramSize;
    }
    else if(testDistance != -1){
      if(testDistance<distance){
        result = array[i];
        distance = testDistance;
      }
    }
  }

  printf("%d\n", result);

  return 0;
}
