#include <stdio.h>
#define SIZE 255

//how many times does the number at that position exists in the array
int howMany(int* arr,unsigned char paramSize,unsigned char position){
  int number = arr[position];
  unsigned char times = 0;
  for(unsigned char i=0;i<paramSize;i++){
    if(arr[i]==number){
      times++;
    }
  }
  return times;
}

//returns the number that appears the most on the array
int  computeMode(int* arr, int paramSize){
  int number,times, testNumber, testTimes;
  for(unsigned char i=0;i<paramSize;i++){
    if(i == 0){
      number = arr[0];
      times = howMany(arr,paramSize,0);
    }
    else{
      if(arr[i]!=number){
        testNumber = arr[i];
        testTimes = howMany(arr,paramSize,i);
        if(testTimes>times){
          number = testNumber;
          times = testTimes;
        }
      }
    }
  }
  return number;
}

int main(int argc, char const *argv[]) {
  int h[SIZE] = {0};
  unsigned char paramSize;

  scanf("%hhu", &paramSize);

  for(int i=0;i<paramSize;i++){
    scanf("%u", &h[i]);
  }

  printf("%d\n", computeMode(&h[0],paramSize));

  return 0;
}
