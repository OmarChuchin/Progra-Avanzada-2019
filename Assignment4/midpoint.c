#include <stdio.h>

int maxim(int a,int b,int c);
int mini(int a,int b,int c);
int foreverAlone(int *array,int max,int min);

int main(int argc, char const *argv[]) {
  int a,b,c;
  scanf("%d\n", &a);
  scanf("%d\n", &b);
  scanf("%d",   &c);

  int arr[3]= {a,b,c};

  int max = maxim(a,b,c);
  int min = mini(a,b,c);
  int midd = foreverAlone(&arr[0],max,min);

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

int foreverAlone(int *array,int max,int min){
  for(int i=0;i<3;i++){
    if(array[i]!=max && array[i]!=min){
      return array[i];
    }
  }
  return -1;
}
