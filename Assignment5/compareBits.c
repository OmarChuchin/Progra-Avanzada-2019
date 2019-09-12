#include <stdio.h>

unsigned short countOnes(int number){
  int bitCounter=1;
  int counter=0;
  unsigned short result = 0;
  while (counter<32) {
    if(bitCounter & number){
      result++;
    }
    counter++;
    bitCounter= bitCounter<<1;
  }
  return result;
}

int main(int argc, char const *argv[]) {
  int a,b;
  scanf("%d\n", &a);
  scanf("%d",   &b);

  unsigned short countA=countOnes(a),countB=countOnes(b);
  if(countA==countB){
    printf("%d\n", 0);
  }
  else if (countA>countB) {
    printf("%d\n", 1);
  }
  else{
    printf("%d\n", -1);
  }

  return 0;
}
