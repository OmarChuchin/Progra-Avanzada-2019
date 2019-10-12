#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_POINTS 100
#define LIMIT_OF_NUMBERS 10000
#define LENGTH_OF_PRINT_ROW 20

//section for orders
char ascendingCompare(int a,int b);
char descendingCompare(int a,int b);

//section specific for Arrays
void bubbleSort(int* const array,const unsigned int* const arraySize,char (*orderPtr)(int,int));
void generateRandomArray(int* const array,const unsigned int* const arraySize);
void printArray(const int* const array, const unsigned int* const arraySize);


//tests space
char testAscendingInt(const int* const array,const unsigned int* const arraySize);
char testDescendingInt(const int* const array,const unsigned int* const arraySize);
char testMutableInt(const int* const array,const unsigned int* const arraySize, char (*orderPtr)(int,int));



int main(int argc, char const *argv[]){
    
    unsigned int numberOfPoints = NUMBER_OF_POINTS;

    if (argc>1){
        numberOfPoints = atoi(argv[1]);
    }

    int array[numberOfPoints];

    //------------------------Sorting now in ascending order------------------------------------------
    generateRandomArray(&array[0],&numberOfPoints);
    
    printf("Array before order\n");
    printArray(&array[0],&numberOfPoints);

    printf("\nArray after sorting in Ascending Order\n");
    bubbleSort(&array[0],&numberOfPoints,ascendingCompare);
    printArray(&array[0],&numberOfPoints);
    printf("Is the array ordered? : %d\n",testAscendingInt(&array[0],&numberOfPoints));
    printf("Is the array ordered? : %d\n",testMutableInt(&array[0],&numberOfPoints,ascendingCompare));


    //--------------------------End of sort in ascending order---------------------------------------


    //Pause to check the info before going to second sorting round.
    char Continue;
    printf("Press enter to continue ");
    scanf("%c",&Continue);



    //------------------------Sorting now in descending order----------------------------------------
    printf("\nResetting array...\n");
    generateRandomArray(&array[0],&numberOfPoints);
    printf("New Random array\n");
    printArray(&array[0],&numberOfPoints);

    printf("\n\nArray after sorting in Descending order\n");
    bubbleSort(&array[0],&numberOfPoints,descendingCompare);
    printArray(&array[0],&numberOfPoints);
    printf("Is the array ordered? : %d\n",testDescendingInt(&array[0],&numberOfPoints));
    printf("Is the array ordered? : %d\n",testMutableInt(&array[0],&numberOfPoints,descendingCompare));

    //--------------------------End of sort in descending order---------------------------------------    
    return 0;
}

char ascendingCompare(int a, int b){
    if(a<b){
        return -1;
    }
    else if(a>b)
    {
        return 1;
    }
    return 0;
    
}

char descendingCompare(int a, int b){
    if(a>b){
        return -1;
    }
    else if(a<b)
    {
        return 1;
    }
    return 0;
    
}

void bubbleSort(int* const array,const unsigned int* const arraySize,char (*orderPtr)(int,int)){
    for (int i = *arraySize-1; i > 1; i--){
        for (int j = 0; j < i; j++){
            if((*orderPtr)(array[j],array[j+1])==1){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }    
}

void generateRandomArray(int* const array,const unsigned int* const arraySize){

    for (int  i = 0; i < *arraySize; i++)
    {
        array[i] = rand() % LIMIT_OF_NUMBERS;
    }
    
}

void printArray(const int* const array, const unsigned int* const arraySize){
    printf("[");
    for (int i = 0; i < *arraySize; i++){
        if(i>0 && i<*arraySize-1 && i%(LENGTH_OF_PRINT_ROW)==0){
            printf("\n");
        }
        printf("%d",array[i]);
        if(i!=*arraySize-1){
            printf(",");
        }
    }
    printf("]\n");    
}

char testAscendingInt(const int* const array,const unsigned int* const arraySize){
    for(unsigned int i = 0; i<*arraySize -1 ; i++){
        if(array[i+1]<array[i]){
            return -1;
        }
    }
    return 1;
}

char testDescendingInt(const int* const array,const unsigned int* const arraySize){
    for(unsigned int i = 0; i<*arraySize -1 ; i++){
        if(array[i+1]>array[i]){
            return -1;
        }
    }
    return 1;
}

char testMutableInt(const int* const array,const unsigned int* const arraySize, char (*orderPtr)(int,int)){
    for (unsigned int i = 0; i < *arraySize-1 ; i++){
        if((orderPtr)(array[i],array[i+1])==1){
            return -1;
        }
    }
    return 1;
}
