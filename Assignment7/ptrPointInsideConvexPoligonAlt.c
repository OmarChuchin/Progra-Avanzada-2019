#include <stdio.h>
#include <stdlib.h>

#define dInfinity 0xFFFFFFFFFFFFFFFF

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    unsigned short pointCount;
    Point** points;
}Polygon;

double slope(const Point* const a,const Point* const b){
    double up = b->y - a->y;
    double down = b->x - b->x;
    if (down == 0.0){
        double result = dInfinity;
        if (up<0){
            result *=-1;
        }
        return result;
    }
    return up/down; 
}


char isPointInsideConvexPolygon(const Polygon* const polygon,const Point* const target){
    for(unsigned short i = 0; i < polygon->pointCount ; i++){
        double top = 0.0, bottom = 0.0;
        for(unsigned short j = 0; j < polygon->pointCount ; j++){
            if(j!=i){
                double temp = slope(polygon->points[i],polygon->points[j]);
                if(temp>top){
                    top = temp;
                }
                if(temp<bottom){
                    bottom = temp;
                }
            }
        }
        double targetSlope = slope(polygon->points[i],target);
        if(targetSlope>top || targetSlope<bottom){
            return 0;
        }
    }
    return 1;
}

void printPoint(const Point* const point){
    printf("(%d,%d)\n",point->x,point->y);
}

void printPolygon(const Polygon* const polygon){
    for(short i=0; i< polygon->pointCount; i++){
        printPoint(polygon->points[i]);
    }
}

void freePolygon(Polygon* const polygon){
    for(unsigned short i = polygon->pointCount-1; i>0 ; i--){
        free(polygon->points[i]);
    }
    free(polygon->points[0]);
    free(polygon->points);
    free(polygon);
}


int main(void){
    
    
    unsigned short numberOfPoints;
    

    scanf("%hu",&numberOfPoints);

    if(numberOfPoints<3){
        // printf("The number of points is not above 3\nTherefore it is not a polygon\nGood day\n");
        printf("%d\n",0);
        return 1;
    }

    Polygon* polygon = malloc(sizeof(Polygon));
    polygon->pointCount = numberOfPoints;
    Point** ptrPointArray = malloc(sizeof(Point*)*polygon->pointCount);

    // unsigned short count = 0;
    // scanf("%hu",&count);

    // for(unsigned short i = 0;i<count;i++){
    for(unsigned short i = 0; i<polygon->pointCount;i++){
        Point* ptrPoint = malloc(sizeof(Point));
        scanf("%d",&ptrPoint->x);
        scanf("%d",&ptrPoint->y);
        // printPoint(ptrPoint);
        ptrPointArray[i] = ptrPoint;
    }

    polygon->points = ptrPointArray;

    // for (unsigned short i = 0; i < count; i++){
    //     printPoint(ptrPointArray[i]);
    // }
    

    // printPolygon(polygon);

    Point* target = malloc(sizeof(Point));
    scanf("%d",&target->x);
    scanf("%d",&target->y);

    printf("%hu\n",isPointInsideConvexPolygon(polygon,target));

    // printPolygon(polygon);
    free(target);
    freePolygon(polygon);    

    return 0;
}

