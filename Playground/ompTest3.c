#include <stdio.h>
#include <math.h>
#include <omp.h>
#include <time.h>

#define NUM_THREADS 4

int main(void){

    double sum[NUM_THREADS] = {0};

    const int numSteps = 10000000;
    const int highX = 10;
    const double deltaX = 1.0*highX/numSteps;
    double auc = 0;
    int nThreads = 0;

    omp_set_num_threads(NUM_THREADS);
    clock_t start,end;
    start = clock();
    #pragma omp parallel
    {
        const int id = omp_get_thread_num();
        const int currentNThreads = omp_get_num_threads();
        if(id == 0){
            nThreads = currentNThreads;
        }
        sum[id] = 0;
        for (int i = 0; i < numSteps; i+=currentNThreads){
            double leftX = (i-1)*deltaX;
            double rightX = (i+1)*deltaX;
            double b1 = sqrt(leftX<0 ? 0 : leftX);
            double b2 = sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(rightX))))))))));
            sum[id] += .5*(b1+b2)*deltaX;
        }
    }

    for (int i = 0; i < nThreads; i++){
        auc += sum[i];
    }
    end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("The integral value is: %f\n",auc);
    printf("The time of exec was %f\n",cpu_time_used);
    return 0;
}
