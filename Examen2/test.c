#include <stdio.h>

enum MinutiaType {Ending,Bifurcation,Unknown};

typedef struct
{
    unsigned short x;
    unsigned short y;
    float angle;
    enum MinutiaType type;

} Minutia;

int printMinutia(Minutia* minutia){

    printf("%hu,%hu,%.2f,%d",minutia->x,minutia->y,minutia->angle,minutia->type);
    printf("\n");
    return 0;
}

int main(int argc, char const *argv[]){
    
    Minutia test = {10,
        10,
        10.5,
        Ending};

    printMinutia(&test);

    return 0;
}


