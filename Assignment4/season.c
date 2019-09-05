#include <stdio.h>

int main(int argc, char const *argv[]) {
  int day,month;

  scanf("%d\n",&month);
  scanf("%d", &day);

  if((month<1 || month>12) || (day<1 || day>31)){
    printf("%s\n", "There is something wrong with the parameters you gave me");
    return 1;
  }

  month*=100;
  int date = month+day;

  if(date>315 && date<616){
    printf("%s\n", "Spring");
  }
  else if(date>615 && date<916){
    printf("%s\n", "Summer");
  }
  else if (date>915 && date<1216) {
    printf("%s\n", "Fall");
  }
  else{
    printf("%s\n", "Winter");
  }

  return 0;
}
