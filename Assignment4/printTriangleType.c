#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a,b,c;
  scanf("%d\n", &a);
  scanf("%d\n", &b);
  scanf("%d",   &c);

  if(a==b && b==c){
    printf("%s\n", "equilateral");
  }
  else if(a!=b && b!=c && a!=c){
    printf("%s\n", "scalene");
  }
  else{
    printf("%s\n", "isosceles");
  }
  return 0;
}
