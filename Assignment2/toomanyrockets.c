#include <stdio.h>
#include <stdlib.h>

int houston(int number);

int main(int argc, char const *argv[]) {
  /*if(argc<2){
    puts("There are missing arguments");
    return 1;
  }*/
  //int number_of_rockets = atoi(argv[1]);
  int number_of_rockets;
  scanf("%d", &number_of_rockets);
  houston(number_of_rockets);
  return 0;
}

int justTheTip(int number){
  char number_of_rows = 3;
  char top[] =    "   /\\   ";
  char middle[] = "  /  \\  ";
  char botom[] =  " /    \\ ";
  for(char i=0;i<number_of_rows;i++){
    for(int j=0;j<number;j++){
      switch (i) {
        case 0:
          printf("%s", top);
          break;
        case 1:
          printf("%s", middle);
          break;
        default:
          printf("%s", botom);
          break;
        }
        if(j<number-1){
          printf(" ");
        }
    }
    printf("\n");
  }
  return 0;
}

int sexyBody(int number){
  char number_of_rows = 2;
  char sexy[] = "| Viva |";
  char body[] = "|Mexico|";
  for(char i=0;i<number_of_rows;i++){
    for(int j=0;j<number;j++){
      switch (i) {
        case 0:
          printf("%s", sexy);
          break;
        default:
          printf("%s", body);
          break;
      }
      if(j<number-1){
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}

int metalbody(int number){
  short number_of_rows = 4;
  char top[]= "+------+";
  char middle[]= "|      |";
  for(char i=0;i<number_of_rows;i++){
    for(int j=0;j<number;j++){
      switch (i) {
        case 0:
        case 3:
          printf("%s", top);
          break;
        default:
          printf("%s", middle);
          break;
      }
      if(j<number-1){
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}

int ignition(int number){
  return justTheTip(number);
}

int houston(int number_of_rockets){
  justTheTip(number_of_rockets);
  metalbody(number_of_rockets);
  sexyBody(number_of_rockets);
  metalbody(number_of_rockets);
  ignition(number_of_rockets);
  return 0;
}
