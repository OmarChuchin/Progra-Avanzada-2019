#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Como el programa tiene la libreria math.h es necesario compilar de la siguiente forma
gcc main.c -o result -lm
*/

typedef enum {numerical,nominal} FeatureType;

typedef struct {
    double* features;
    FeatureType* featureType;
    short length;
}Instance;

double computeEuclideanDissimilarity(const Instance* const ptrInstanceA,const Instance* const ptrInstanceB);

Instance* findNearestNeighbor(const Instance* const arrInstance,short length,const Instance* const query,double (*computeDissimilarity)(const Instance* const ptrInstanceA,const Instance* const ptrInstanceB));

char testComputeDissimilarity1();

char testComputeDissimilarity2();

char testComputeDissimilarity3();

char testComputeDissimilarity4();

char testFindNearestNeighbor1();

char testFindNearestNeighbor2();

char testFindNearestNeighbor3();

char testFindNearestNeighbor4();