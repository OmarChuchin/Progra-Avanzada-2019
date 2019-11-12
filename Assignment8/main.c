#include "main.h"

void freeInstance(Instance* instance){
    free(instance->features);
    free(instance->featureType);
    free(instance);
}

Instance* createInstanceArray(short size,short instanceSize){
    Instance* array = malloc(sizeof(Instance)*size);

    for (short i = 0; i < size; i++){
        array[i].length = instanceSize;
        // double* feat = malloc(sizeof(double)*instanceSize);
        // FeatureType* type = malloc(sizeof(FeatureType)*instanceSize);
        double* feat = calloc(sizeof(double),instanceSize);
        FeatureType* type = calloc(sizeof(FeatureType),instanceSize);
        array[i].features = feat;
        array[i].featureType = type;
    }

    return array;
}

void freeInstanceArray(Instance* array,short size){
    for (short i = 0; i < size; i++){
        free(array[i].features);
        free(array[i].featureType);
    }
    free(array);
}

double computeEuclideanDissimilarity(const Instance* const ptrInstanceA,const Instance* const ptrInstanceB){
    double dissimilarity = 0.0;
    // short length = (ptrInstanceA->length<ptrInstanceB->length)? ptrInstanceA->length : ptrInstanceB->length;
    if(ptrInstanceA->length==0 || ptrInstanceB->length==0){
        return -1;
    }
    if(ptrInstanceA->length!=ptrInstanceB->length){
        return -2;
    }
    short length = ptrInstanceA->length;
    for (short i = 0; i < length; i++){
        double temp = 0.0;
        //Numerical scenario
        if(ptrInstanceA->featureType[i] == numerical && ptrInstanceB->featureType[i] == numerical){
            temp = ptrInstanceA->features[i] - ptrInstanceB->features[i];
        }
        //Nominal scenario
        else if(ptrInstanceA->featureType[i] == nominal && ptrInstanceB->featureType[i] == nominal){
            if(ptrInstanceA->features[i]!=ptrInstanceB->features[i]){
                temp = 1;
            }
        }
        //Campechaneado
        else{
            return -3;
        }
        
        dissimilarity += temp*temp;
    }   
    return sqrt(dissimilarity);
}

Instance* findNearestNeighbor(const Instance* const arrInstance,short length,const Instance* const query,double (*computeDissimilarity)(const Instance* const ptrInstanceA,const Instance* const ptrInstanceB)){
    Instance* result;
    double resultDistance = __DBL_MAX__;
    for (short i = 0; i < length; i++){
        double tempDistance = computeDissimilarity(&arrInstance[i],query);
        // printf("%d,%f,%f\n",&arrInstance[i],resultDistance,tempDistance);
        if(tempDistance<0){
            result = (int)tempDistance;
            return result;
        }
        else{
            if(tempDistance<resultDistance){
                resultDistance = tempDistance;
                result = &arrInstance[i];
            }
        }
    }
    return result;
}

char testComputeDissimilarity1(){
    short sizeA = 0;
    Instance* instanceA = malloc(sizeof(Instance));
    instanceA->length=sizeA;

    short sizeB = 1;
    Instance* instanceB = malloc(sizeof(Instance));
    double* feature = malloc(sizeof(double)*sizeB);
    FeatureType* type = malloc(sizeof(FeatureType)*sizeB);

    feature[0] = 5;
    type[0] = numerical;

    instanceB->length = sizeB;
    instanceB->features = feature;
    instanceB->featureType = type;

    double result = computeEuclideanDissimilarity(instanceA,instanceB);
    if(result == -1){
        result = 1;
    }
    else{
        result = 0;
    }
    
    freeInstance(instanceA);
    freeInstance(instanceB);
    return result;
}

char testComputeDissimilarity2(){
    short sizeA = 2;
    Instance* instanceA = malloc(sizeof(Instance));
    double* featureA = malloc(sizeof(double)*sizeA);
    FeatureType* typeA = malloc(sizeof(FeatureType)*sizeA);
    
    for (short i = 0; i < sizeA; i++){
        featureA[i] = i;
        typeA[i] = numerical;
    }

    instanceA->length = sizeA;
    instanceA->features = featureA;
    instanceA->featureType = typeA;

    short sizeB = 1;
    Instance* instanceB = malloc(sizeof(Instance));
    double* featureB = malloc(sizeof(double)*sizeB);
    FeatureType* typeB = malloc(sizeof(FeatureType)*sizeB);

    for (short i = 0; i < sizeB; i++){
        featureB[i] = i;
        typeB[i] = numerical;
    }
    
    instanceB->length = sizeB;
    instanceB->features = featureB;
    instanceB->featureType = typeB;

    double result = computeEuclideanDissimilarity(instanceA,instanceB);
    if(result == -2){
        result = 1;
    }
    else{
        result = 0;
    }
    
    freeInstance(instanceA);
    freeInstance(instanceB);
    return result;
}

char testComputeDissimilarity3(){
    short sizeA = 5;
    Instance* instanceA = malloc(sizeof(Instance));
    double* featureA = malloc(sizeof(double)*sizeA);
    FeatureType* typeA = malloc(sizeof(FeatureType)*sizeA);
    
    for (short i = 0; i < sizeA; i++){
        featureA[i] = i;
        typeA[i] = numerical;
    }

    instanceA->length = sizeA;
    instanceA->features = featureA;
    instanceA->featureType = typeA;

    short sizeB = 5;
    Instance* instanceB = malloc(sizeof(Instance));
    double* featureB = malloc(sizeof(double)*sizeB);
    FeatureType* typeB = malloc(sizeof(FeatureType)*sizeB);

    for (short i = 0; i < sizeB; i++){
        featureB[i] = i;
        typeB[i] = nominal;
    }
    
    instanceB->length = sizeB;
    instanceB->features = featureB;
    instanceB->featureType = typeB;

    double result = computeEuclideanDissimilarity(instanceA,instanceB);
    if(result == -3){
        result = 1;
    }
    else{
        result = 0;
    }
    
    freeInstance(instanceA);
    freeInstance(instanceB);
    return result;
}

char testComputeDissimilarity4(){
    short sizeA = 5;
    Instance* instanceA = malloc(sizeof(Instance));
    double* featureA = malloc(sizeof(double)*sizeA);
    FeatureType* typeA = malloc(sizeof(FeatureType)*sizeA);
    
    for (short i = 0; i < sizeA; i++){
        featureA[i] = i;
        if(i%2==0){
            typeA[i] = numerical;
        }
        else{
            typeA[i] = nominal;
        }
    }

    instanceA->length = sizeA;
    instanceA->features = featureA;
    instanceA->featureType = typeA;

    short sizeB = 5;
    Instance* instanceB = malloc(sizeof(Instance));
    double* featureB = malloc(sizeof(double)*sizeB);
    FeatureType* typeB = malloc(sizeof(FeatureType)*sizeB);

    for (short i = 0; i < sizeB; i++){
        featureB[i] = i;
        if(i%2==0){
            typeB[i] = numerical;
        }
        else{
            typeB[i] = nominal;
        }
    }
    
    instanceB->length = sizeB;
    instanceB->features = featureB;
    instanceB->featureType = typeB;

    //Ambos tienen exactamente los mismos puntos por lo tanto la disimilitud debe ser 0.
    double result = computeEuclideanDissimilarity(instanceA,instanceB);
    if(result == 0){
        result = 1;
    }
    else{
        result = 0;
    }
    
    freeInstance(instanceA);
    freeInstance(instanceB);
    return result;
}

char testFindNearestNeighbor1(){
    short size = 5;
    Instance* instance = malloc(sizeof(Instance));
    double* feature = malloc(sizeof(double)*size);
    FeatureType* type = malloc(sizeof(FeatureType)*size);
    
    for (short i = 0; i < size; i++){
        feature[i] = i;
        type[i] = numerical;
    }

    instance->length = size;
    instance->features = feature;
    instance->featureType = type;

    short sizeOfArray = 1, sizeOfInstance = 0;
    Instance* instArray = createInstanceArray(sizeOfArray,sizeOfInstance);

    // instArray[0].length = 0;
    
    int result = (int)findNearestNeighbor(instArray,sizeOfArray,instance,computeEuclideanDissimilarity);
    if(result == -1){
        result = 1;
    }
    else{
        result = 0;
    }
    
    freeInstance(instance);
    freeInstanceArray(instArray,sizeOfArray);
    return result;
}

char testFindNearestNeighbor2(){
    short size = 5;
    Instance* instance = malloc(sizeof(Instance));
    double* feature = malloc(sizeof(double)*size);
    FeatureType* type = malloc(sizeof(FeatureType)*size);
    
    for (short i = 0; i < size; i++){
        feature[i] = i;
        type[i] = numerical;
    }

    instance->length = size;
    instance->features = feature;
    instance->featureType = type;

    short sizeOfArray = 5, sizeOfInstance = 4;
    Instance* instArray = createInstanceArray(sizeOfArray,sizeOfInstance);
    
    int result = (int)findNearestNeighbor(instArray,sizeOfArray,instance,computeEuclideanDissimilarity);
    if(result == -2){
        result = 1;
    }
    else{
        result = 0;
    }
    
    freeInstance(instance);
    freeInstanceArray(instArray,sizeOfArray);
    return result;
}

char testFindNearestNeighbor3(){
    short size = 5;
    Instance* instance = malloc(sizeof(Instance));
    double* feature = malloc(sizeof(double)*size);
    FeatureType* type = malloc(sizeof(FeatureType)*size);
    
    //Todos los elementos seran de tipo numerical
    for (short i = 0; i < size; i++){
        feature[i] = i;
        type[i] = numerical;
    }

    instance->length = size;
    instance->features = feature;
    instance->featureType = type;

    short sizeOfArray = 5, sizeOfInstance = 5;
    Instance* instArray = createInstanceArray(sizeOfArray,sizeOfInstance);

    //Al menos un elemento sera de tipo nominal por lo que saltara el error y no terminara de manera correcta.
    for (short i = 0; i < sizeOfArray; i++){
        for (short j = 0; j < sizeOfInstance; j++){
            instArray[i].features[j] = i+j;
            // (i+j)%2 == 0 ? instArray[i].featureType[j] = numerical : instArray[i].featureType[j] = nominal;
            if((i+j)%2 == 0){
                instArray[i].featureType[j] = numerical;
            } else {
                instArray[i].featureType[j] = nominal;
            }
        }
    }
    
    int result = (int)findNearestNeighbor(instArray,sizeOfArray,instance,computeEuclideanDissimilarity);
    if(result == -3){
        result = 1;
    }
    else{
        result = 0;
    }
    freeInstance(instance);
    freeInstanceArray(instArray,sizeOfArray);
    return result;
}

char testFindNearestNeighbor4(){
    short size = 30;
    Instance* instance = malloc(sizeof(Instance));
    double* feature = malloc(sizeof(double)*size);
    FeatureType* type = malloc(sizeof(FeatureType)*size);
    
    //La mitad de los elementos seran nominal y la otra sera numerical en orden de 1 en 1.
    for (short i = 0; i < size; i++){
        feature[i] = size;//5
        if(i%2==0){
            type[i] = numerical;
        }
        else{
            type[i] = nominal;
        }
    }

    instance->length = size;
    instance->features = feature;
    instance->featureType = type;

    //Debido a que el maximo numero es el doble que el numero al que esta inicializado el query
    //El pointer que me regresara sera el de la mitad (sizeOfInstance) cuya disimilitud sera 0.
    short sizeOfInstance = size,sizeOfArray = sizeOfInstance*2;
    Instance* instArray = createInstanceArray(sizeOfArray,sizeOfInstance);

    for (short i = 0; i < sizeOfArray; i++){
        // printf("%hd,%d\n",i,&instArray[i]);
        for (short j = 0; j < sizeOfInstance; j++){
            instArray[i].features[j] = sizeOfArray-i;
            //La mitad de los elementos seran nominal y la otra sera numerical en orden de 1 en 1.
            if(j%2==0){
                instArray[i].featureType[j] = numerical;
            }
            else{
                instArray[i].featureType[j] = nominal;
            }
        }
    }
    
    Instance* resultPtr = findNearestNeighbor(instArray,sizeOfArray,instance,computeEuclideanDissimilarity);
    char result;
    if(resultPtr==&instArray[sizeOfInstance]){
        result = 1;
    } else{
        // printf("%d\n",resultPtr);
        result = 0;
    }
    
    freeInstance(instance);
    freeInstanceArray(instArray,sizeOfArray);
    return result;
}

char prettyPrint(char (*testFunction)()){
    char result = testFunction();
    if(result==1){
        printf("Success\n");
    }
    else{
        printf("Failure\n");
    }
    return result;
}

int main(){
    //Compute Dissimilarity Tests
    prettyPrint(testComputeDissimilarity1);
    prettyPrint(testComputeDissimilarity2);
    prettyPrint(testComputeDissimilarity3);
    prettyPrint(testComputeDissimilarity4);
    //Find Nearest Neighbor Tests
    prettyPrint(testFindNearestNeighbor1);
    prettyPrint(testFindNearestNeighbor2);
    prettyPrint(testFindNearestNeighbor3);
    prettyPrint(testFindNearestNeighbor4);
    return 0;
}
