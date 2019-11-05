#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define dInfinity 0xFFFFFFFFFFFFFFFF
#define PI 3.14159265

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    unsigned short pointCount;
    Point** points;
}Polygon;

void printPoint(const Point* const point){
    printf("(%d,%d)\n",point->x,point->y);
}

void printPolygon(const Polygon* const polygon){
    for(short i=0; i< polygon->pointCount; i++){
        printPoint(polygon->points[i]);
    }
}

double slope(const Point* const a,const Point* const b){
    double up = b->y - a->y;
    double down = b->x - b->y;
    if (down == 0.0){
        double result = dInfinity;
        if (up<0){
            result *= -1;
        }
        return result;
    }
    return up/down; 
}

char sector(const Point* const origin, const Point* const point){
    int tempX,tempY;
    tempX = point->x - origin->x;
    tempY = point->y - origin->y;

    if(tempX == 0 || tempY == 0){
        if(tempX == 0 && tempY == 0){
            return 0;
        }
        else{
            if(tempX == 0){
                if(tempY > 0){
                    return -2;
                }
                return -4;
            }
            else{
                if(tempX > 0){
                    return -1;
                }
                return -3;
            }
        }
    }


    if(tempX >0){
        if(tempY > 0){
            return 1;
        }
        return 4;
    }
    else{
        if(tempY > 0){
            return 2;
        }
        return 3;
    }
}

double completeAngle(char section, double angle){
    double newAngle;

    if(section<1){
        switch (section){
        case 0:case -1:
            return 0;
        case -2:
            newAngle = PI/2;
            break;
        case -3:
            newAngle = PI;
            break;
        case -4:
            newAngle = 3*PI/4;
            break;
        default:
            break;
        }
        return newAngle;
    }

    switch (section){
        case 1:
            newAngle = angle;
            break;
        case 2:case 3:
            newAngle = PI + angle;
            break;
        case 4:
            newAngle = 2*PI +angle;
            break;
        default:
            newAngle = 0;
            break;
    }
    return newAngle;
}

double radians(const Point* const a,const Point* const b){
    // double result = 0.0;

    double tanSlope = slope(a,b);
    tanSlope = atan(tanSlope);

    // char section = sector(a,b);

    // result = completeAngle(section,tanSlope);

    return tanSlope; 
}

double pointDistance(const Point* const a,const Point* const b){
    double xAxis = a->x - b->x;
    xAxis*=xAxis;
    double yAxis = a->y - b->y;
    yAxis*=yAxis;
    return sqrt(xAxis + yAxis);
}

Point* closestPoint(const Point* const target, const Polygon* const polygon){
    Point* result = polygon->points[0];
    double distance = pointDistance(target,result);
    for (unsigned short i = 1; i < polygon->pointCount; i++){
        double tempDistance = pointDistance(target,polygon->points[i]);
        if(tempDistance < distance){
            result = polygon->points[i];
            distance = tempDistance;
        }
    }
    return result;
}


char isPointInsideConvexPolygon(const Polygon* const polygon,const Point* const target){
    // printPolygon(polygon);
    // printf("\n");
    Point* closest = closestPoint(target,polygon);
    // double top = 0.0, bottom = 0.0;
    // char targetSector = sector(closestPoint,target);
    double targetRadians = completeAngle(sector(closest,target),radians(closest,target));
    for(unsigned short i = 0; i < polygon->pointCount ; i++){
        char baseAngleSector = sector(closest,polygon->points[i]);
        double baseAngleOriginal = radians(closest,polygon->points[i]);
        double baseAngle = completeAngle(baseAngleSector,baseAngleOriginal);
        for (unsigned short j = 0; j < polygon->pointCount; j++){
            char topAngleSector = sector(closest,polygon->points[j]);
            double topAngleOriginal = radians(closest,polygon->points[j]);
            double topAngle = completeAngle(topAngleSector,topAngleOriginal);
            if(baseAngle<targetRadians && targetRadians<topAngle){
                if((topAngle-baseAngle)<=18.00){
                    return 1;
                }
            }
        }
        
        
    }
    // printPoint(polygon->points[i]);
    // printf("top = %.2f\ntarget = %.2f\nbottom = %.2f\n",top,targetRadians,bottom);
    // if(targetRadians>top || targetRadians<bottom){
    //     return 0;
    // }
    return 0;
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

