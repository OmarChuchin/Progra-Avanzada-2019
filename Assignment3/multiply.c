#include <stdio.h>

#define times 2

int main(int argc, char const *argv[]) {
  int number;
  scanf("%d", &number);
  printf("%d times %d = %d\n",number,times,number*times );
  return 0;
}
