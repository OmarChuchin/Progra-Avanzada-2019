#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
} Point;

double slope(const Point* const a,const Point* const b){
    int down = (b->x - a->x);
    if(down == 0){
        return 0.0;
    }
    const double result = (b->y - a->y)/down;
    return result;
}

char areCollinear(const Point* const a,const Point* const b,const Point* const c){
    const double firstSlope = slope(a,b);
    const double secondSlope = slope(b,c);
    if(firstSlope == secondSlope){
        return 1;
    }
    return 0;
}


int main(void){
    
    Point* const a = malloc(sizeof(Point));
    Point* const b = malloc(sizeof(Point));
    Point* const c = malloc(sizeof(Point));

    scanf("%d",&a->x);
    scanf("%d",&a->y);
    scanf("%d",&b->x);
    scanf("%d",&b->y);
    scanf("%d",&c->x);
    scanf("%d",&c->y);

    printf("%u\n",areCollinear(a,b,c));
    free(a);
    free(b);
    free(c);
    return 0;
}
