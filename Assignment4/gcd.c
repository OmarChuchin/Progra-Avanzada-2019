#include <stdio.h>

int gcd(int a,int b);

int main(int argc, char const *argv[]) {
  int top,counter=0;
  scanf("%d", &top);

  for(int i=1;i<top;i++){
    if(gcd(top,i)==1){
      counter++;
      //printf("%d\n", i);
    }
  }

  printf("%d\n", counter);
  return 0;
}

int gcd(int a,int b){
  if(a==1 || b==1){
    return 1;
  }
  if(a<b){
    return gcd(b,a);
  }
  int left=a%b;
  if(left==0){
    return b;
  }
  return gcd(b,left);
}
