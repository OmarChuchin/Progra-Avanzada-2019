#include "stdio.h"

int printer(double x,double y,int decimalSizeX,int decimalSizeY);

int main(void) {
int z = 5;
double bubble = 867.5309;

double x = 10.01;
double y = 8.0;
printer(x,y,2,1);
printer(x, bubble,2,4);
printf("The value from main is: %0.4f\n", bubble);
printf("z = %d\n", z);

return 0;
}

int printer(double x,double y,int decimalSizeX,int decimalSizeY) {
  //System.out.println("x = " + double x + " and y = " + y);
  switch (decimalSizeX) {
    case 1:
      printf("x = %0.1f ",x);
      break;
    case 2:
      printf("x = %0.2f ",x);
      break;
    case 3:
      printf("x = %0.3f ",x);
      break;
    case 4:
      printf("x = %0.4f ",x);
      break;
    default:
      printf("x = %f ",x);
  }
  switch (decimalSizeY) {
    case 1:
      printf("and y = %0.1f\n",y);
      break;
    case 2:
      printf("and y = %0.2f\n",y);
      break;
    case 3:
      printf("and y = %0.3f\n",y);
      break;
    case 4:
      printf("and y = %0.4f\n",y);
      break;
    default:
      printf("x = %f ",x);
  }
  return 0;
}
