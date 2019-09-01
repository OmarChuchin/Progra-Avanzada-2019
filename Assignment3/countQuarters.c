#include <stdio.h>

int countQuarters(int money);

int main(int argc, char const *argv[]) {
  int money;
  scanf("%d", &money);
  printf("%d\n", countQuarters(money));
  return 0;
}

int countQuarters(int money){
  int cents = money%100;
  return cents/25;
}
