#include <stdio.h>
#include <math.h>
#include <time.h>

int main(void){
    const int numSteps = 1000000000;
    const int highX = 10;
    const double deltaX = 1.0*highX/numSteps;
    double auc = 0;

    clock_t start,end;
    start = clock();
    for (int i = 0; i < numSteps; i++)
    {
        double leftX = (i-1)*deltaX;
        double rightX = (i+1)*deltaX;
        double b1 = sqrt(leftX<0 ? 0 : leftX);
        double b2 = sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(rightX))))))))));
        auc += .5*(b1+b2)*deltaX;
    }
    printf("The integral value is: %f\n",auc);
    end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("The time of exec was %f\n",cpu_time_used);
    return 0;
}
