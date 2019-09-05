#include "stdio.h"

// void ftoc(double tempf, double *tempc) {
//   tempc = (tempf - 32) * 5 / 9;
// }
#define ftoc(tempf) (tempf - 32) * 5 / 9

int main(void) {

  double tempf = 98.6;
  double tempc = ftoc(tempf);
  printf("Body temp in C is: %0.1f\n", tempc);

  return 0;
}
