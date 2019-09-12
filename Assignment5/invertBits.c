#include <stdio.h>

int main(int argc, char const *argv[]) {
  int x,p,n;
  scanf("%d\n", &x);
  scanf("%d\n", &p);
  scanf("%d",   &n);

  int result = 0;
  int bitCounter = 1;
  for(int i=0;i<p;i++){
    if(x & bitCounter){
      result+=bitCounter;
    }
    bitCounter=bitCounter<<1;
  }
  for(int i=0;i<n;i++){
    result+=bitCounter;
    if(bitCounter & x){
      result-=bitCounter;
    }
    bitCounter=bitCounter<<1;
  }
  while(bitCounter>0){
    if(bitCounter&x){
      result+=bitCounter;
    }
    bitCounter=bitCounter<<1;
  }
  printf("%u\n", result);
  return 0;
}
