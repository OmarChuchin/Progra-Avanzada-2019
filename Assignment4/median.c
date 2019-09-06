#include <stdio.h>

// int median(int a,int b,int c){
//   if(a<b && b<c){
//     return b;
//   }
//   if(a>b){
//     return median(b,a,c);
//   }
//   return median(a,c,b);
// }

int main(int argc, char const *argv[]) {
  int a,b,c,result;

  scanf("%d\n", &a);
  scanf("%d\n", &b);
  scanf("%d", &c);

  if(b>a && b<c || b>c && b<a){
    printf("%d\n", b);
  }
  else if(b>c && a<c || a>c && b<c){
    printf("%d\n", c);
  }
  else{
    printf("%d\n", a);
  }


  //printf("%d\n", median(a,b,c));

  return 0;
}
