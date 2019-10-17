#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    unsigned short pointCount;
    Point** points;
}Polygon;

void freePolygon(Polygon* const polygon){
    for(short i = polygon->pointCount-1; i>=0 ; i--){
        free(polygon->points[i]);
    }
    free(polygon->points);
    free(polygon);
}

void printPoint(const Point* const point){
    printf("(%d,%d)\n",point->x,point->y);
}

void printPolygon(const Polygon* const polygon){
    for(short i=0; i< polygon->pointCount; i++){
        printPoint(polygon->points[i]);
    }
}


int main(void){
    
    Point** ptrPointArray = malloc(sizeof(Point*));
    Polygon* polygon = malloc(sizeof(Polygon));
    

    scanf("%hu",&polygon->pointCount);
    // unsigned short count = 0;
    // scanf("%hu",&count);

    // for(unsigned short i = 0;i<count;i++){
    for(unsigned short i = 0; i<polygon->pointCount;i++){
        Point* ptrPoint = malloc(sizeof(Point));
        scanf("%d",&ptrPoint->x);
        scanf("%d",&ptrPoint->y);
        printPoint(ptrPoint);
        ptrPointArray[i] = ptrPoint;
    }

    polygon->points = ptrPointArray;

    // for (unsigned short i = 0; i < count; i++){
    //     printPoint(ptrPointArray[i]);
    // }
    

    // printPolygon(polygon);

    freePolygon(polygon);

    return 0;
}

