#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a;
  scanf("%d",&a);
  int result;
  result = a&1;
  //printf("%d\n", result);
  if(result){
    printf("odd\n");
  }
  else{
    printf("even\n");
  }
  return 0;
}
