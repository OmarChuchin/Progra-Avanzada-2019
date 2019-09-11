#include <stdio.h>

int isPerfect(int number);

int main(int argc, char const *argv[]) {
  int top,notFoundOne=1;
  scanf("%d", &top);

  printf("Perfect numbers up to %d:", top);

  for(int i=0;i<=top;i++){
    if(isPerfect(i)){
      notFoundOne = 0;
      printf(" %d", i);
    }
  }

  if(notFoundOne){
    printf("%s\n", "none where found");
  }
  else{
    printf("\n");
  }

  return 0;
}

int isPerfect(int number){
  if(number<1){
    return 0;
  }

  int sum=0;
  for(int i=1;i<=number/2;i++){
    if(number%i==0){
      sum+=i;
    }
  }
  if(sum==number){
    return 1;
  }
  return 0;
}
