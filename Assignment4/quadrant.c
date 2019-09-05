#include <stdio.h>

int quadrant(double x,double y){
  if(x==0 || y==0){
    return 0;
  }
  if(x>0){
    if(y>0){
      return 1;
    }
    else{
      return 4;
    }
  }
  else{
    if(y>0){
      return 2;
    }
    else{
      return 3;
    }
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  double x,y;
  scanf("%lf\n", &x);
  scanf("%lf",   &y);

  printf("%d\n", quadrant(x,y));

  return 0;
}
