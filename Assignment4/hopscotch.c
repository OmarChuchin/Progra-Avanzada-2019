#include <stdio.h>

int main(int argc, char const *argv[]) {
  int hops;
  scanf("%d", &hops);
  int boolean = 1;
  int counter=0;
  for(int i=0;i<hops;){
    if(boolean){
      printf("   %d   \n", ++counter);
      boolean--;
    }
    else{
      boolean++;
      counter++;
      printf("%d     %d\n", counter++,counter);
      i++;
    }
  }
  printf("   %d   \n", ++counter);
  return 0;
}
