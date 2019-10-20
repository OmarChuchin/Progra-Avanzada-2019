#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum MinutiaType {Ending,Bifurcation,Unknown};

#define RANDOM_NUMBER_LIMIT 100
#define TEST_ARRAY_SIZE 0

/**
 * Structure of a minutia
 */
typedef struct{
    unsigned short x;
    unsigned short y;
    float angle;
    enum MinutiaType type;
} Minutia;

/**
 * Array of minutia pointer, 
 */ 
typedef struct {
    unsigned short length;
    Minutia** minutiae;
} MinutiaArray;

/**
 * Dynamically allocates a Minutia type pointer with the parameters passed.
 */
Minutia* createMinutia(unsigned short x,unsigned short y,float angle,enum MinutiaType type);

/**
 * Dynamically allocates an Array of Minutia pointers with the size passed as a parameter
 */
MinutiaArray* createMinutiaArray(unsigned short size);

/**
 * Recieves a pointer to a Minutia structure and prints its values in the console
 */ 
int printMinutia(const Minutia* const minutia);

/**
 * Recieves a pointer to a MinutiaArray that was dynamically allocated using the createMinutiaArray function
 * which it will proceed to dynamically free in order to prevent memory leaks.
 */ 
void releaseMinutiaArray(MinutiaArray* array);

/**
 * Basically the a == b function but for two Minutia structure pointers.
 * They are recieved as pointers to prevent excesive use of memory 
 */
char compareMinutia(const Minutia* const minutiaA, const Minutia* const minutiaB);

/**
 * The header of the function which after implementation will decide how to calculate the distance between 
 * two Minutia structures
 */
double computeDistance(const Minutia* const ptrMA, const Minutia* const ptrMB);

/**
 * Function which returns the pointer to a Minutia within the MinutiaArray -> array which using the function of computeDistance
 * will decide it's the relative center of the group of Minutia.
 */
Minutia* findCentroid(const MinutiaArray* const array, double (*computeDistance)(const Minutia* const MinutiaA,const Minutia* const MinutiaB));

/**
 * A function implemented to automatize if the function findCentroid is working properly.
 */
char testFindCentroid();
