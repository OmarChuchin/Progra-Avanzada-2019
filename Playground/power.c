#include <stdio.h>
#include <stdlib.h>

long long power(long long result,int times){
  if(times<2){
    return result;
  }
  times--;
  return result*power(result,times);
}

int main(int argc, char const *argv[]) {
  if(argc<3){
    puts("There are missing arguments");
    return 1;
  }
  int number  = atoi(argv[1]);
  int times   = atoi(argv[2]);
  unsigned long long result = power(number,times);
  printf("%llu\n", result);
  return 0;
}
