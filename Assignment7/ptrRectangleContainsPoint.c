#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
} Point;

typedef struct {
    Point* origin;
    int height;
    int width;
} Rectangle;

char withinRectangle(const Rectangle* const r,const Point* const p){
    Point limit;
    limit.x = r->origin->x + r->width;
    limit.y = r->origin->y + r->height;
    char result = 0;

    if(limit.x >= p->x && p->x >= r->origin->x && limit.y >= p->y && p->y >= r->origin->y){
        result++;
    }
    
    return result;
}

void freeRectangle(Rectangle* const r){
    free(r->origin);
    free(r);
}

int main(void){
    Rectangle* const figure = malloc(sizeof(Rectangle));
    Point* const a = malloc(sizeof(Point));
    Point* const b = malloc(sizeof(Point));

    scanf("%d",&b->x);
    scanf("%d",&b->y);
    // figure->origin->x = b->x;
    // figure->origin->y = b->y;
    figure->origin = b;
    // free(b);
    // printf("%d,%d\n",figure->origin->x,figure->origin->y);
    scanf("%d",&figure->width);
    scanf("%d",&figure->height);
    scanf("%d",&a->x);
    scanf("%d",&a->y);
    

    printf("%u\n",withinRectangle(figure,a));

    free(a);
    freeRectangle(figure);

    return 0;
}


