#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int a,b;
  scanf("%d\n",&a);
  scanf("%d",&b);
  a=abs(a);
  b=abs(b);
  printf("%d\n", a>b ? a:b);
  return 0;
}
