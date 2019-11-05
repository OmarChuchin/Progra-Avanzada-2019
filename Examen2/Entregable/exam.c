#include "exam.h"

/*
Since we are using math.h in this code,
the compilation should be like this
gcc exam.c -o result -lm
*/

double computeDistance(const Minutia* const ptrMA, const Minutia* const ptrMB){
    double result = 0.0;

    double xAxis = ptrMA->x - ptrMB->x;
    xAxis *= xAxis;
    double yAxis = ptrMA->y - ptrMB->y;
    yAxis *= yAxis;

    return sqrt(xAxis + yAxis);
}

int main(void){

    printf("%d\n",testFindCentroid());

    return 0;
}

Minutia* createMinutia(unsigned short x,unsigned short y,float angle, MinutiaType type){
    Minutia* result = malloc(sizeof(Minutia));
    result->x = x;
    result->y = y;
    result->angle = angle;
    result->type = type;
    return result;
}

MinutiaArray* createMinutiaArray(unsigned short size){
    MinutiaArray* result = malloc(sizeof(MinutiaArray));
    result->length = size;
    Minutia* array = malloc(sizeof(Minutia)*size);
    // Minutia* array = calloc(size,sizeof(Minutia));
    for(unsigned short i = 0; i<size; i++){
        array[i].x = 0;
        array[i].y = 0;
        array[i].angle = 0;
        array[i].type = 0;
    }
    result->minutiae = array;
    return result;
}

int testFindCentroid(){
    MinutiaArray* array = createMinutiaArray(TEST_ARRAY_SIZE);

    for(unsigned short i = 1; i < array->length ; i++){
        array->minutiae[i].x       =   i;
        array->minutiae[i].y       =   i;
        array->minutiae[i].angle   =   i*1.1;
        //Just a quick reminder 
        //MinutiaType {Ending,Bifurcation,Unknown} 
        array->minutiae[i].type    =   Unknown;
    }

    unsigned int middle = TEST_ARRAY_SIZE/2;

    // if the number is even
    if(TEST_ARRAY_SIZE%2 == 0){
        middle--;
    }

    Minutia* firstMinutia = &array->minutiae[middle]; // right in the middle because the points (x,y) follow the equation f(x) = x
    //therefore the point in the middle of the array is the one with the smallest accumulated distance

    Minutia* centroid = findCentroid(array,computeDistance);

    // prints the values of the minutia found to be supposed the same
    // printMinutia(firstMinutia);
    // printMinutia(centroid);

    int result = 0;

    if(firstMinutia == centroid){
        result++;
    }

    releaseMinutiaArray(array);

    return result;
}

char compareMinutia(const Minutia* const minutiaA, const Minutia* const minutiaB){
    if(minutiaA->x != minutiaB->x){
        return 0;
    }
    if(minutiaA->y != minutiaB->y){
        return 0;
    }
    if(minutiaA->angle != minutiaB->angle){
        return 0;
    }
    if(minutiaA->type != minutiaB->type){
        return 0;
    }
    return 1;
}

int printMinutia(const Minutia* const minutia){
    printf("%hu,%hu,%.2f,%d",minutia->x,minutia->y,minutia->angle,minutia->type);
    printf("\n");
    return 0;
}

void releaseMinutiaArray(MinutiaArray* array){
    free(array->minutiae);
    free(array);
}

Minutia* findCentroid(const MinutiaArray* const array, double (*computeDistance)(const Minutia* const MinutiaA,const Minutia* const MinutiaB)){
    unsigned short centroid = array->length; //to prove it is not set to the correct anwer by default
    double centroidDistance = 0xFFFFFFFFFFFFFFFF; //Max distance in a double 
    for(unsigned short i=0 ; i < array->length ; i++){
        double accumulatedDistance = 0;
        for(unsigned short j=0 ; j < array->length ; j++){
            if(j!=i){
                accumulatedDistance += computeDistance(&array->minutiae[i],&array->minutiae[j]);
            }
        }
        if(accumulatedDistance < centroidDistance){
            //If distance to the other points is smaller
            //then switch the two Minutae
            centroidDistance = accumulatedDistance;
            centroid = i;
        }
    }

    return &array->minutiae[centroid];
}