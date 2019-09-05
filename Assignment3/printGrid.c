#include <stdio.h>

int main(int argc, char const *argv[]) {
  int rows,columns;
  scanf("%d\n", &rows);
  scanf("%d", &columns);
  for(int i=1;i<=rows;i++){
    for(int j=0;j<columns;j++){
      if(j<columns-1){
        printf("%d, ", i+(j*rows));
      }
      else{
        printf("%d\n", i+(j*rows));
      }
    }
  }
  return 0;
}
