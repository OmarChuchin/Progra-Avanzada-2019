#include <stdio.h>

int maxim(int a,int b,int c);
int mini(int a,int b,int c);
int median(int a,int b,int c);

int main(int argc, char const *argv[]) {
  int a,b,c;
  scanf("%d\n", &a);
  scanf("%d\n", &b);
  scanf("%d",   &c);

  int max = maxim(a,b,c);
  int min = mini(a,b,c);
  int midd = median(a,b,c);

  int diff = max-min;
  diff/=2;
  if((min+diff)==midd){
    printf("%s\n", "true");
  }
  else{
    printf("%s\n", "false");
  }
  return 0;
}

int median(int a,int b,int c){
  if(a<b && b<c){
    return b;
  }
  if(a>b){
    return median(b,a,c);
  }
  return median(a,c,b);
}

int maxim(int a,int b,int c){
  int result=a;
  if(result<b){
    result=b;
  }
  if(result<c){
    result=c;
  }
  return result;
}

int mini(int a,int b,int c){
  int result=a;
  if(result>b){
    result=b;
  }
  if(result>c){
    result=c;
  }
  return result;
}
