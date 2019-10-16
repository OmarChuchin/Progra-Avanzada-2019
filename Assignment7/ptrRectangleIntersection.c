#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int x;
    int y;
} Point;

typedef struct {
    Point* origin;
    int height;
    int width;
} Rectangle;

Rectangle* allocateRectangle(){
    Rectangle* r = (Rectangle*)malloc(sizeof(Rectangle));
    Point* p = (Point*)malloc(sizeof(Point));
    scanf("%d",&p->x);
    scanf("%d",&p->y);
    r->origin = p;
    scanf("%d",&r->width);
    scanf("%d",&r->height);
    return r;
}

void freeRectangle(Rectangle* const r){
    free(r->origin);
    free(r);
}

void printRectangle(const Rectangle* const r){
    printf("%d\n",r->origin->x);
    printf("%d\n",r->origin->y);
    printf("%d\n",r->width);
    printf("%d\n",r->height);
}

Rectangle* uniteRectangles(const Rectangle* const r1,const Rectangle* const r2){
    Point* const pointOfResult = malloc(sizeof(Point));
    Rectangle* const result = malloc(sizeof(Rectangle));

    result->origin = pointOfResult;

    result->origin->x = (r1->origin->x > r2->origin->x) ? r1->origin->x : r2->origin->x;
    result->origin->y = (r1->origin->y > r2->origin->y) ? r1->origin->y : r2->origin->y;

    Point topR1,topR2;
    topR1.x = r1->origin->x + r1->width;
    topR1.y = r1->origin->y + r1->height;

    topR2.x = r2->origin->x + r2->width;
    topR2.y = r2->origin->y + r2->height;

    Point pointResult;
    pointResult.x = (topR1.x < topR2.x) ? topR1.x : topR2.x;
    pointResult.y = (topR1.y < topR2.y) ? topR1.y : topR2.y;
    
    result->width = pointResult.x - result->origin->x;
    result->height = pointResult.y - result->origin->y;

    return result;
}

int main(void){
    
    Rectangle* r1 = allocateRectangle();
    Rectangle* r2 = allocateRectangle();

    Rectangle* const result = uniteRectangles(r1,r2);

    freeRectangle(r1);
    freeRectangle(r2);

    printf("\nEl resultado es\n");
    printRectangle(result);
    freeRectangle(result);

    return 0;
}
