#include <stdio.h>
#include <omp.h>

int main(void){
    
    char signal = 0;
    omp_set_num_threads(2);
    char* string;
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        
    }
    return 0;
}
