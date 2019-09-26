#include <stdio.h>
#define SIZE 255

int isPrime(int* primes,int size,unsigned int objective){
  int i=0;
  while (i<size) {
    if(objective%primes[i]==0){
      return 0;
    }
    i++;
  }
  return 1;
}

unsigned int sieve(int* arr,unsigned int top){
  unsigned int size = 1;
  unsigned char boolean = 0;

  for(int i=0;i<size && boolean == 0;i++){
    if(top<arr[i]) {
      size = i+1;
      boolean=1;
    }
  }

  if(boolean){
    unsigned int number = arr[size-1] + 1;
    while (number<top) {
      if(isPrime(arr,size,number)){
        arr[size]=number;
        size++;
      }
      number++;
    }
  }
  return size;
}

int main(int argc, char const *argv[]) {
  unsigned int top;
  unsigned int array[SIZE] = {2};

  scanf("%u", &top);

  int arraySize = sieve(&array[0], top);

  for(int i=1;i<arraySize;i++){
    printf("%u\n", array[i]);
  }
  return 0;
}
