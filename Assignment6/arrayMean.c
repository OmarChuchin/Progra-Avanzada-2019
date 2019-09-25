#include "stdio.h"
#define SIZE 10

int sum(int* arr,int arrSize){
  int result = 0;
  for(int i=0;i<arrSize;i++){
    result+=arr[i];
  }
  return result;
}

int main(void) {
  unsigned int h[SIZE] = {0};
  scanf("%u%u%u%u%u%u%u%u%u%u", &h[0], &h[1], &h[2], &h[3], &h[4], &h[5], &h[6], &h[7], &h[8], &h[9]);

  int res = sum(&h[0],SIZE);
  double result = res/(double)SIZE;

  printf("%.1f\n", result);

  return 0;
}
