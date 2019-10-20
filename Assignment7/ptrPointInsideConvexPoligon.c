#include <stdio.h>
#include <stdlib.h>

#define infinity !0

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    unsigned short pointCount;
    Point* points;
}Polygon;


char isPointCloser(const Point* const init,const Point* const target,const Point* const limit){


    return 0;
}

char isPointInsideConvexPolygon(const Polygon* const Polygon,const Point* const target){

    return 0;
}

void printPoint(const Point* const point){
    printf("(%d,%d)\n",point->x,point->y);
}

void printPolygon(const Polygon* const polygon){
    for(short i=0; i< polygon->pointCount; i++){
        printPoint(&polygon->points[i]);
    }
}

void freePolygon(Polygon* const polygon){
    // for(unsigned short i = polygon->pointCount-1; i>=0 ; i--){
    //     free(polygon->points[i]);
    // }
    free(polygon->points);
    free(polygon);
}


int main(void){
    
    
    unsigned short numberOfPoints;
    

    scanf("%hu",&numberOfPoints);

    if(numberOfPoints<3){
        printf("The number of points is not above 3\nTherefore it is not a polygon\nGood day\n");
        return 1;
    }

    Polygon* polygon = malloc(sizeof(Polygon));
    polygon->pointCount = numberOfPoints;
    Point* ptrPointArray = malloc(sizeof(Point)*numberOfPoints);

    // unsigned short count = 0;
    // scanf("%hu",&count);

    // for(unsigned short i = 0;i<count;i++){
    for(unsigned short i = 0; i<polygon->pointCount;i++){
        Point* ptrPoint = malloc(sizeof(Point));
        scanf("%d",&ptrPoint[i].x);
        scanf("%d",&ptrPoint[i].y);
    }

    polygon->points = ptrPointArray;

    // for (unsigned short i = 0; i < count; i++){
    //     printPoint(ptrPointArray[i]);
    // }
    

    // printPolygon(polygon);

    // Point* target = malloc(sizeof(Point));
    // scanf("%d",&target->x);
    // scanf("%d",&target->y);

    // printf("%hu",isPointInsideConvexPolygon(polygon,target));
    // free(target);
    printPolygon(polygon);
    freePolygon(polygon);    

    return 0;
}

