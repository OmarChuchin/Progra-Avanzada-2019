#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//This code has to be compiled as 
// gcc <this code> -o result -lm

typedef struct {
    int x;
    int y;
    int z;
} TDPoint;

double distance(const TDPoint* const a,const TDPoint* const b){
    
    int dx = a->x - b->x;
    int dy = a->y - b->y;
    int dz = a->z - b->z;

    dx *= dx;
    dy *= dy;
    dz *= dz;

    double result = sqrt(dx+dy+dz);
    return result;
}

int main(void){
    
    TDPoint* const a = malloc(sizeof(TDPoint));
    TDPoint* const b = malloc(sizeof(TDPoint));

    scanf("%d", &a->x);
    scanf("%d", &a->y);
    scanf("%d", &a->z);

    scanf("%d", &b->x);
    scanf("%d", &b->y);
    scanf("%d", &b->z);

    printf("%.2f\n",distance(a,b));

    free(a);
    free(b);

    return 0;
}
