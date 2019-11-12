#include "main.h"

Instance* createInstance(short length){
    Instance* instance = malloc(sizeof(Instance));
    instance->length = length;
    double* feature = malloc(sizeof(double)*length);
    instance->features = feature;
    FeatureType* type = malloc(sizeof(FeatureType)*length);
    instance->featureType = type;
    return instance;
}

Instance* createInstanceArray(short size,short instanceSize){
    Instance* array = malloc(sizeof(Instance)*size);

    for (short i = 0; i < size; i++){
        array[i].length = instanceSize;
        double* feat = malloc(sizeof(double)*instanceSize);
        FeatureType* type = malloc(sizeof(FeatureType)*instanceSize);
        array[i].features = feat;
        array[i].featureType = type;
    }

    return array;
}

void freeInstance(Instance* instance){
    free(instance->features);
    free(instance->featureType);
    free(instance);
}

void freeInstanceArray(Instance* array,short size){
    for (short i = 0; i < size; i++){
        free(array[i].features);
        free(array[i].featureType);
    }
    free(array);
}

int main(){
    
    Instance* array = createInstanceArray(5,5);
    
    freeInstanceArray(array,5);

    return 0;
}
