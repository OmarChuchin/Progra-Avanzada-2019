#include <stdio.h>

int printRange(int a,int b){
  if(a<b){
    for(int i=a;i<=b;i++){
      printf("%d ", i);
    }
  }
  else{
    for(int i=a;i>=b;i--){
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}

int main(int argc, char const *argv[]) {
  int a,b;
  scanf("%d\n", &a);
  scanf("%d", &b);
  return printRange(a,b);
}
