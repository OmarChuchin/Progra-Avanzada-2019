#include <stdio.h>

int min(int a,int b,int c);

int main(int argc, char const *argv[]) {
  int a,b,c;
  scanf("%d\n", &a);
  scanf("%d\n", &b);
  scanf("%d", &c);
  printf("%d\n", min(a,b,c));
  return 0;
}

int min(int a,int b,int c){
  int result;
  result = a<b ? a:b;
  result = result<c ? result:c;
  return result;
}
