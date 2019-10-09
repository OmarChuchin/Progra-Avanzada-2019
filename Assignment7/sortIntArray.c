#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_POINTS 100
#define LIMMIT_OF_NUMBERS 100

char ascendingCompare(int a,int b);
char descendingCompare(int a,int b);
void bubbleSort(int* array,unsigned int* arraySize,char (*orderPtr)(int,int));
void generateRandomArray(int* array,unsigned int* arraySize);
void printArray(int* array, unsigned int* arraySize);

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

    //--------------------------End of sort in ascending order---------------------------------------

    //Pause to check the info before going to second sorting round.
    char Continue;
    printf("Press enter to continue ");
    scanf("%c",&Continue);



    //------------------------Sorting now in descending order----------------------------------------
    printf("Resetting array...\n");
    generateRandomArray(&array[0],&numberOfPoints);
    printf("New Random array\n");
    printArray(&array[0],&numberOfPoints);

    printf("Array after sorting in descending order\n");
    bubbleSort(&array[0],&numberOfPoints,descendingCompare);
    printArray(&array[0],&numberOfPoints);
    //--------------------------End of sort in descending order---------------------------------------

    printf("I am done... :)");
    
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

void bubbleSort(int* array,unsigned int* arraySize,char (*orderPtr)(int,int)){
    printf("I got up to here!");
    for (int i = *arraySize-1; i > 1; i++){
        for (int j = 0; j < i; j++){
            if((*orderPtr)(array[j],array[j+1])==1){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }    
}

void generateRandomArray(int* array,unsigned int* arraySize){

    for (int  i = 0; i < *arraySize; i++)
    {
        array[i] = rand() % LIMMIT_OF_NUMBERS;
    }
    
}

void printArray(int* array,unsigned int* arraySize){
    printf("[");
    for (int i = 0; i < *arraySize; i++){
        if(i>0 && i<*arraySize-1 && i%20==0){
            printf("\n");
        }
        printf("%d",array[i]);
        if(i!=*arraySize-1){
            printf(",");
        }
    }
    printf("]\n");    
}